#include "../include/tp2_ex1_tools.h"

#include <queue>
#include <random>

#include <pmp/algorithms/SurfaceTriangulation.h>

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
    pmp::MeshViewer::process_imgui();
    
    if( ImGui::Button("Color non triangular faces") )
    {
        colorNonTriangularFaces(mesh_);
        update_mesh();
    }

    if( ImGui::Button("Triangulate mesh") )
    {
        mesh_.remove_face_property<pmp::Color>(mesh_.face_property<pmp::Color>("f:color"));
        pmp::SurfaceTriangulation triangulation(mesh_);
        triangulation.triangulate();
        update_mesh();
    }
}

void colorNonTriangularFaces(pmp::SurfaceMesh& mesh)
{
    auto fcolors = mesh.face_property<pmp::Color>("f:color", pmp::Color(0.5, 1.0, 0.5));

    for( auto const& f : mesh.faces() )
    {
        size_t nVerticesInCurrFace = mesh.valence(f);
        if( nVerticesInCurrFace > 3 )
        {
            fcolors[f] = pmp::Color(1.0, 0.5, 0.5);
        }
    }
}