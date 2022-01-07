#include "../include/tp1_ex3_tools.h"

#include <imgui.h>


TP1_Ex3_MeshViewer::TP1_Ex3_MeshViewer(const char* title,
                                       int width, int height,
                                       bool showgui) : pmp::MeshViewer(title,
                                                                       width, height,
                                                                       showgui)
{
    // Nothing to do
}

TP1_Ex3_MeshViewer::TP1_Ex3_MeshViewer(const char* title,
                                        int width, int height,
                                        const pmp::SurfaceMeshGL& mesh,
                                        bool showgui) : pmp::MeshViewer(title,
                                                                        width, height,
                                                                        showgui)
{
    mesh_ = mesh;
    colorMeshVertices(mesh_, pmp::Color(1.0, 0.0, 0.0));

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

void TP1_Ex3_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    if( ImGui::Button("Color in red") )
    {
        colorMeshFaces(mesh_, pmp::Color(1.0, 0.0, 0.0));
        update_mesh();
    }

    if( ImGui::Button("Color in green") )
    {
        colorMeshFaces(mesh_, pmp::Color(0.0, 1.0, 0.0));
        update_mesh();
    }
}

void colorMeshVertices(pmp::SurfaceMesh& mesh,
                       const pmp::Color& color)
{
    mesh.vertex_property<pmp::Color>("v:color", color);
}

void colorMeshFaces(pmp::SurfaceMesh& mesh,
                    const pmp::Color& color)
{
    mesh.face_property<pmp::Color>("f:color", color);
}