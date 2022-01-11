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

TP2_Ex6_MeshViewer::~TP2_Ex6_MeshViewer()
{
    /* ! STUDENTS TODO ! */
    // Fill if required
}

void TP2_Ex6_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    /* ! STUDENTS TODO ! */
    // Add a button trigerring the computation of the geodesic distance from each vertex to a querry source vertex
}

void TP2_Ex6_MeshViewer::mouse(int button, int action, int mods)
{
    /* ! STUDENTS TODO ! */
    // Get the vertex under a user's left click and color it in red
}

void colorVerticesPerGeodesic(pmp::SurfaceMesh&             mesh
                              /* ! STUDENTS TODO ! */
                              // Fill if required
                              )
{
    /* ! STUDENTS TODO ! */
    // Color each vertex according to its geodesic distance to a source vertex
}