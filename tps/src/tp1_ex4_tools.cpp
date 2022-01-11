#include "../include/tp1_ex4_tools.h"

#include <random>

#include <imgui.h>

TP1_Ex4_MeshViewer::TP1_Ex4_MeshViewer(const char* title,
                                       int width, int height,
                                       bool showgui) : pmp::MeshViewer(title,
                                                                       width, height,
                                                                       showgui)
{
    // Nothing to do
}

TP1_Ex4_MeshViewer::TP1_Ex4_MeshViewer(const char* title,
                                        int width, int height,
                                        const pmp::SurfaceMeshGL& mesh,
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

void TP1_Ex4_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    if( ImGui::Button("Color in red") )
    {
        auto test = mesh_.vertex_property<pmp::Color>("v:color");
        mesh_.remove_vertex_property(test);
        colorMeshFaces(mesh_, pmp::Color(1.0, 0.0, 0.0));
        update_mesh();
    }

    if( ImGui::Button("Color in green") )
    {
        auto test = mesh_.vertex_property<pmp::Color>("v:color");
        mesh_.remove_vertex_property(test);
        colorMeshFaces(mesh_, pmp::Color(0.0, 1.0, 0.0));
        update_mesh();
    }

    if( ImGui::Button("Color vertices (random)") )
    {
        colorMeshVerticesRandomHue(mesh_);
        update_mesh();
    }
}

void colorMeshFaces(pmp::SurfaceMesh& mesh,
                    const pmp::Color& color)
{
    /* ! STUDENTS TODO ! */
    // Color the faces of the input mesh (see properties)
}

void colorMeshVertices(pmp::SurfaceMesh& mesh,
                       const pmp::Color& color)
{
    /* ! STUDENTS TODO ! */
    // Color the vertices of the input mesh (see properties)
}

void colorMeshVerticesRandomHue(pmp::SurfaceMesh& mesh)
{
    /* ! STUDENTS TODO ! */
    // Color each vertex of the input mesh with a random color (see properties): use hsv color and convert it to rgb
}