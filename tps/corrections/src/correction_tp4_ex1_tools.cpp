#include "../include/correction_tp4_ex1_tools.h"

#include <pmp/algorithms/SurfaceFeatures.h>

#include <imgui.h>

TP4_Ex1_MeshViewer::TP4_Ex1_MeshViewer(const char* title,
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

void TP4_Ex1_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    ImGui::SliderInt("Angle", &angle_, 0, 90);
    if( ImGui::Button("Mark features") )
    {
        pmp::SurfaceFeatures surfFeatures(mesh_);
        surfFeatures.clear();
        surfFeatures.detect_angle(angle_);

        auto vColors  = mesh_.vertex_property<pmp::Color>("v:color");
        auto eFeature = mesh_.edge_property<bool>("e:feature");

        for( auto const &v : mesh_.vertices() )
        {
            int nFeatureEdges = 0;
            for( auto const &he : mesh_.halfedges(v) )
            {
                pmp::Edge e = mesh_.edge(he);

                if( eFeature[e] == true )
                {
                    nFeatureEdges++;
                }
            }
            if( nFeatureEdges == 0 )
            {
                vColors[v] = pmp::Color(0.8, 0.8, 0.8);
            }
            else if( nFeatureEdges == 1 )
            {
                vColors[v] = pmp::Color(1.0, 0.0, 0.0);
            }
            else if( nFeatureEdges == 2 )
            {
                vColors[v] = pmp::Color(0.0, 0.0, 1.0);
            }
            else
            {
                vColors[v] = pmp::Color(0.0, 1.0, 0.0);
            }
        }
    }

    update_mesh();
}