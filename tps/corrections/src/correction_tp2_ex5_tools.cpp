#include "../include/correction_tp2_ex5_tools.h"

#include <queue>
#include <random>

#include <pmp/algorithms/DifferentialGeometry.h>

#include <imgui.h>

TP2_Ex5_MeshViewer::TP2_Ex5_MeshViewer(const char* title,
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

void TP2_Ex5_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();
    
    if( ImGui::Button("Compute dual") )
    {
        pmp::dual(mesh_);
        update_mesh();
    }
}