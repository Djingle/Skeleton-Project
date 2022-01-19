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

    /* ! STUDENTS TODO ! */
    // Add a button triggering the colorization of vertices based on their manifoldness
}

void colorVerticesPerManifoldness(pmp::SurfaceMesh& mesh)
{
    /* ! STUDENTS TODO ! */
    // Color vertices based on their manifoldness
}

bool isWatertight(const pmp::SurfaceMesh& mesh)
{
    /* ! STUDENTS TODO ! */
    // Return true if the mesh is watertight, false otherwise
    return true;
}