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
    /* ! STUDENTS TODO ! */
    // Create a GUI with one button triggering the colorization of the connected components
}

void labelVerticesPerConnectedComponent(pmp::SurfaceMesh&  mesh,
                                        const std::string& storagePropertyName)
{
    /* ! STUDENTS TODO ! */
    // Store for each vertex the label of its connected component into a property nammed storagePropertyName
}

void vertex_property_to_color(pmp::SurfaceMeshGL& mesh,
                              const std::string&  propertyName)
{
    /* ! STUDENTS TODO ! */
    // Converts the property nammed storagePropertyName into colors
}