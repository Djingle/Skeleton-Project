#include "../include/tp2_ex2_tools.h"

#include <queue>
#include <random>

#include <pmp/algorithms/SurfaceHoleFilling.h>

#include <imgui.h>

TP2_Ex2_MeshViewer::TP2_Ex2_MeshViewer(const char* title,
                                        int width, int height,
                                        pmp::SurfaceMeshGL& mesh,
                                        bool showgui) : pmp::MeshViewer(title,
                                                                        width, height,
                                                                        showgui)
{
    mesh_ = mesh;

    // Update scene center and bounds
    pmp::BoundingBox bb = mesh_.bounds();
    set_scene((pmp::vec3)bb.center(), 0.5 * bb.size());

    // Set draw mode
    if( mesh_.n_faces() == 0 )
    {
        set_draw_mode("Points");
    }
    else
    {
        set_draw_mode("Hidden Line");
    }

    // Compute face & vertex normals, update face indices
    update_mesh();

    // Set viewer angle parameter
    mesh_.set_crease_angle(0);
}

void TP2_Ex2_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();
    
    if( ImGui::Button("Color border faces") )
    {
        colorBorderFaces(mesh_);
        update_mesh();
    }

    if( ImGui::Button("Fill holes") )
    {
        auto fColors = mesh_.face_property<pmp::Color>("f:color");
        mesh_.remove_face_property<pmp::Color>(fColors);
        fillHoles(mesh_);
        update_mesh();
    }

    if( ImGui::Button("Delete small CC") )
    {
        std::string         ccLabelPropName = "v:ccLabel";
        std::vector<size_t> ccSizes;
        labelVerticesPerConnectedComponent(mesh_, ccLabelPropName, ccSizes);
        removeSmallConnectedComponents(mesh_, ccLabelPropName, ccSizes, 40);
        update_mesh();
    }
}

void colorBorderFaces(pmp::SurfaceMesh& mesh)
{
    auto fcolors = mesh.face_property<pmp::Color>("f:color", pmp::Color(0.5, 1.0, 0.5));

    for( auto const& f : mesh.faces() )
    {
        if( mesh.is_boundary(f) )
        {
            fcolors[f] = pmp::Color(1.0, 0.5, 0.5);
        }
    }
}

void fillHoles(pmp::SurfaceMesh& mesh)
{
    pmp::SurfaceHoleFilling shf(mesh);

    for( auto const& f : mesh.faces() )
    {
        if( mesh.is_boundary(f) )
        {
            for( auto const& he : mesh.halfedges() )
            {
                if( mesh.is_boundary(he) )
                {
                    shf.fill_hole( he );
                }
            }
        }
    }
}

void labelVerticesPerConnectedComponent(pmp::SurfaceMesh&       mesh,
                                        const std::string&      ccLabelStoragePropertyName,
                                        std::vector< size_t >&  outNVerticesInCc)
{
    outNVerticesInCc.clear();

    auto visitedFlags = mesh.vertex_property<bool>("v:visited", 0);
    auto ccLabel      = mesh.vertex_property<size_t>(ccLabelStoragePropertyName, 0);

    size_t currCcLabel = 0;

    for( auto ccStartV : mesh.vertices() )
    {
        if( visitedFlags[ccStartV] == false )
        {
            size_t nVerticesInCc = 0;

            std::queue<pmp::Vertex> awaiting;
            pmp::Vertex v0 = ccStartV;

            awaiting.push(v0);
            visitedFlags[v0] = true;

            while( !awaiting.empty() )
            {
                pmp::Vertex v = awaiting.front();
                awaiting.pop();

                ccLabel[v] = currCcLabel;
                nVerticesInCc++;

                pmp::SurfaceMesh::VertexAroundVertexCirculator vavc(&mesh, v);
                for( auto const& nv : vavc )
                {
                    if( visitedFlags[nv] == false )
                    {
                        awaiting.push(nv);
                        visitedFlags[nv] = true;
                    }
                }
            }
            
            outNVerticesInCc.push_back(nVerticesInCc);
            currCcLabel++;
        }
    }
}

void removeSmallConnectedComponents(pmp::SurfaceMesh&       mesh,
                                    const std::string&      ccLabelStoragePropertyName,
                                    std::vector< size_t >&  nVerticesInCc,
                                    size_t                  nVerticesMin)
{
    auto ccLabelProp = mesh.vertex_property<size_t>(ccLabelStoragePropertyName);

    for( auto const& v : mesh.vertices() )
    {
        if( nVerticesInCc[ccLabelProp[v]] < nVerticesMin )
        {
            mesh.delete_vertex(v);
        }
    }

    mesh.garbage_collection();
}