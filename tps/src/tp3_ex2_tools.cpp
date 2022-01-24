#include "../include/tp3_ex2_tools.h"

#include <pmp/algorithms/DifferentialGeometry.h>

#include <imgui.h>

TP3_Ex2_MeshViewer::TP3_Ex2_MeshViewer(const char* title,
                                        int width, int height,
                                        pmp::SurfaceMeshGL& mesh,
                                        bool showgui) : pmp::MeshViewer(title,
                                                                        width, height,
                                                                        showgui)
{
    mesh_   = mesh;
    /* ! STUDENTS TODO ! */
    // Fill if required

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

void TP3_Ex2_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    /* ! STUDENTS TODO ! */
    // Complete if necessary
}