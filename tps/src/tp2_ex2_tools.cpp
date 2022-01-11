#include "../include/tp2_ex2_tools.h"

#include <queue>
#include <random>

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
    /* ! STUDENTS TODO ! */
    // Color the bordering faces of a mesh in red
}

void fillHoles(pmp::SurfaceMesh& mesh)
{
    /* ! STUDENTS TODO ! */
    // Fill the holes in the mesh using the "algorithm" module
}

void labelVerticesPerConnectedComponent(pmp::SurfaceMesh&       mesh,
                                        const std::string&      ccLabelStoragePropertyName,
                                        std::vector< size_t >&  outNVerticesInCc)
{
    /* ! STUDENTS TODO ! */
    // See tp1_ex7.cpp + outputs a vector containing the number of vertices in each connected component
}

void removeSmallConnectedComponents(pmp::SurfaceMesh&       mesh,
                                    const std::string&      ccLabelStoragePropertyName,
                                    std::vector< size_t >&  nVerticesInCc,
                                    size_t                  nVerticesMin)
{
    /* ! STUDENTS TODO ! */
    // Remove all vertices belonging to a connected component with less than nVerticesMin vertices
}