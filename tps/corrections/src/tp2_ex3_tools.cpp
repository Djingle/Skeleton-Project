#include "../include/tp2_ex3_tools.h"

#include <queue>
#include <random>

#include <pmp/algorithms/SurfaceHoleFilling.h>

#include <imgui.h>

TP2_Ex3_MeshViewer::TP2_Ex3_MeshViewer(const char* title,
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

void TP2_Ex3_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    if( ImGui::Button("Test manifoldness") )
    {
        colorVerticesPerManifoldness(mesh_);
        update_mesh();
    }
}

void colorVerticesPerManifoldness(pmp::SurfaceMesh& mesh)
{
    size_t nNonManifold = 0;

    auto vColors = mesh.vertex_property<pmp::Color>("v:color");
    for( auto const& v : mesh.vertices() )
    {
        if( mesh.is_manifold(v) )
        {
            vColors[v] = pmp::Color(0.0, 1.0, 0.0);
        }
        else
        {
            vColors[v] = pmp::Color(1.0, 0.0, 0.0);
        }

    }

    std::cout << "The mesh contains " << nNonManifold << " non manifold vertices" << std::endl;
}

bool isWatertight(const pmp::SurfaceMesh& mesh)
{
    for( auto const& he : mesh.halfedges() )
    {
        if( mesh.is_boundary(he) )
        {
            return false;
        }
    }

    return true;
}