#include "../include/tp2_ex6_tools.h"

#include <queue>
#include <random>

#include <imgui.h>

TP2_Ex6_MeshViewer::TP2_Ex6_MeshViewer(const char* title,
                                        int width, int height,
                                        pmp::SurfaceMeshGL& mesh,
                                        bool showgui) : pmp::MeshViewer(title,
                                                                        width, height,
                                                                        showgui)
{
    mesh_   = mesh;
    sg_     = new pmp::SurfaceGeodesic(mesh_);

    // Update scene center and bounds
    pmp::BoundingBox bb = mesh_.bounds();
    set_scene((pmp::vec3)bb.center(), 0.6 * bb.size());

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

TP2_Ex6_MeshViewer::~TP2_Ex6_MeshViewer()
{
    delete sg_;
}

void TP2_Ex6_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    if( ImGui::Button("Compute geodesics") )
    {
        std::vector<pmp::Vertex> seed{begVertex_};
        sg_->compute(seed);
        colorVerticesPerGeodesic(mesh_, sg_);
        update_mesh();
    }
}

void TP2_Ex6_MeshViewer::mouse(int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double x, y;
        cursor_pos(x, y);
        pmp::Vertex vPick = pick_vertex( static_cast<int>(x), static_cast<int>(y) );
        if( mesh_.is_valid(vPick) )
        {
            auto vColors = mesh_.vertex_property<pmp::Color>("v:color");
            for( auto const& v : mesh_.vertices() )
            {
                vColors[v] = pmp::Color(0.3, 0.3, 0.3);
            }

            if( mesh_.is_valid(begVertex_) )
            {
                vColors[begVertex_] = pmp::Color(0.3, 0.3, 0.3);
            }

            begVertex_ = vPick;
            vColors[begVertex_] = pmp::Color(1.0, 0.0, 0.0);
            update_mesh();
        }
    }
}

void colorVerticesPerGeodesic(pmp::SurfaceMesh&             mesh,
                              const pmp::SurfaceGeodesic*   sgPtr)
{
    const pmp::SurfaceGeodesic& sg = *sgPtr;

    std::vector<float> vGeodesics;
    vGeodesics.reserve(mesh.n_vertices());
    for( auto v : mesh.vertices() )
    {
        vGeodesics.push_back(sg(v));
    }
    std::sort(vGeodesics.begin(), vGeodesics.end());

    float vmin  = vGeodesics.front();
    float vmax  = vGeodesics.back();
    float range = vmax - vmin;
    std::cout << vmin << " et " << vmax << std::endl;

    // Convert to colors
    float hue;
    float sat = 1;
    float val = 1;
    float r, g, b;
    auto vColors = mesh.vertex_property<pmp::Color>("v:color");
    for( auto v : mesh.vertices() )
    {
        // min = 0 degres, max = 270 degres = 2/3
        hue = (2.0/3.0) * ( 1 - ((sg(v) - vmin)  / range ));
        ImGui::ColorConvertHSVtoRGB(hue, sat, val, r, g, b);
        vColors[v] = pmp::Color(r, g, b);
        std::cout << sg(v) << " donne " << hue * 360 << std::endl;
    }
}