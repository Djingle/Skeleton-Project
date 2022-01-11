#include "../include/tp2_ex1_tools.h"

#include <queue>
#include <random>

#include <imgui.h>

TP2_Ex1_MeshViewer::TP2_Ex1_MeshViewer(const char* title,
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

void TP2_Ex1_MeshViewer::process_imgui()
{
    /* ! STUDENTS TODO ! */
    // Add one button triggering the colorization of non triangular faces
    // Add one button triggering the triangularization of the mesh (use an algorithm from the "algorithm" module)
}

void colorNonTriangularFaces(pmp::SurfaceMesh& mesh)
{
    /* ! STUDENTS TODO ! */
    // Color the non triangulated faces in a color (e.g. in red) and the triangulated faces in another color (e.g. green)
}