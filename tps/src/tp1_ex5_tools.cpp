#include "../include/tp1_ex5_tools.h"

#include <random>

#include <imgui.h>

TP1_Ex5_MeshViewer::TP1_Ex5_MeshViewer(const char* title,
                                       int width, int height,
                                       /* ! STUDENTS TODO ! */
                                       // Apply an affine transformation to the input mesh (apply in place)
                                       bool showgui) : pmp::MeshViewer(title,
                                                                       width, height,
                                                                       showgui)
                                                                       /* ! STUDENTS TODO ! */
                                                                       // Fill if required
{
    /* ! STUDENTS TODO ! */
    // Fill if required

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
    mesh_.set_crease_angle(crease_angle_);
}

void TP1_Ex5_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    /* ! STUDENTS TODO ! */
    // Add a combobox and select the mesh to display
}