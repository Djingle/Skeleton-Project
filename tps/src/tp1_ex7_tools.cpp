#include "../include/tp1_ex7_tools.h"

#include <queue>
#include <random>

#include <imgui.h>

TP1_Ex7_MeshViewer::TP1_Ex7_MeshViewer(const char* title,
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

void TP1_Ex7_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();
    
    if( ImGui::Button("Color vertices per connected component") )
    {
        std::string storagePropertyName = "v:ccLabel";
        labelVerticesPerConnectedComponent(mesh_, storagePropertyName);
        vertex_property_to_color(mesh_, storagePropertyName);
        update_mesh();
    }
}

void labelVerticesPerConnectedComponent(pmp::SurfaceMesh&  mesh,
                                        const std::string& storagePropertyName)
{
    auto visitedFlags = mesh.vertex_property<int>("v:visited", 0);
    auto ccLabel      = mesh.vertex_property<size_t>(storagePropertyName, 0);

    size_t currCcLabel = 0;
    size_t nFlaged = 0;

    for( auto ccStartV : mesh.vertices() )
    {
        if( visitedFlags[ccStartV] == 0 )
        {
            currCcLabel++;

            std::queue<pmp::Vertex> awaiting;
            pmp::Vertex v0 = ccStartV;

            awaiting.push(v0);
            visitedFlags[v0] = 1;
            nFlaged++;

            while( !awaiting.empty() )
            {
                pmp::Vertex v = awaiting.front();
                awaiting.pop();

                ccLabel[v] = currCcLabel;

                pmp::SurfaceMesh::VertexAroundVertexCirculator vavc(&mesh, v);
                for( auto const& nv : vavc )
                {
                    if( visitedFlags[nv] == 0 )
                    {
                        awaiting.push(nv);
                        visitedFlags[nv] = 1;
                        nFlaged++;
                    }
                }
            }
            std::cout << "CC " << currCcLabel << " start v " << ccStartV  << " sur " << mesh.n_vertices() << " nflags " << nFlaged << std::endl;
        }
    }

    std::cout << "Found " << currCcLabel << " connected components" << std::endl;
}

void vertex_property_to_color(pmp::SurfaceMeshGL& mesh,
                              const std::string&  propertyName)
{
    auto props = mesh.vertex_property<size_t>(propertyName);
    assert(props);

    // sort property values
    std::vector<float> values;
    values.reserve(mesh.n_vertices());
    for( auto v : mesh.vertices() )
    {
        values.push_back(props[v]);
    }
    std::sort(values.begin(), values.end());

    float vmin  = values.front();
    float vmax  = values.back();
    float range = vmax - vmin;

    std::cout << "vmin vmax " << vmin << " " << vmax << std::endl;

    // Convert to colors
    float hue;
    float sat = 1;
    float val = 1;
    float r, g, b;
    auto vColors = mesh.vertex_property<pmp::Color>("v:color");
    for( auto v : mesh.vertices() )
    {
        // min = 0 degres, max = 270 degres = 2/3
        hue = (2.0/3.0) * ( 1 - ((props[v] - vmin)  / range));
        ImGui::ColorConvertHSVtoRGB(hue, sat, val, r, g, b);
        vColors[v] = pmp::Color(r, g, b);
    }
}