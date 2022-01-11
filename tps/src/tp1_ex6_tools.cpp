#include "../include/tp1_ex6_tools.h"

#include <random>

#include <imgui.h>

TP1_Ex6_MeshViewer::TP1_Ex6_MeshViewer(const char* title,
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
    mesh_.set_crease_angle(crease_angle_);
}

void TP1_Ex6_MeshViewer::process_imgui()
{
    /* ! STUDENTS TODO ! */
    // Add two buttons that triggers the colorization of the vertices according to their valence, and the colorization of faces according to their area
}

void colorVerticesPerValence(pmp::SurfaceMeshGL &mesh)
{
    /* ! STUDENTS TODO ! */
    // Store the valence of each vertex in a property named "v:valence"
    // And convert this property into colors
}

void vertex_valence_to_color(pmp::SurfaceMeshGL &mesh)
{
    /* ! STUDENTS TODO ! */
    // Converts the v:valence property into a color property named "v:color"
}

void colorFacesPerArea(pmp::SurfaceMeshGL &mesh)
{
    /* ! STUDENTS TODO ! */
    // Store the area of each face in a property named "f:area"
    // And convert this property into colors
}

void face_area_to_color(pmp::SurfaceMeshGL &mesh)
{
    /* ! STUDENTS TODO ! */
    // Converts the f:area property into a color property named "f:color"
}