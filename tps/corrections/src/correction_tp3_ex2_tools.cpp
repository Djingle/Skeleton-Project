#include "../include/correction_tp3_ex2_tools.h"

#include <pmp/algorithms/DifferentialGeometry.h>

#include <imgui.h>

TP3_Ex2_MeshViewer::TP3_Ex2_MeshViewer(const char* title,
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

void TP3_Ex2_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    if( ImGui::CollapsingHeader("Taubin smoothing") )
    {
        ImGui::SliderInt("NIter", &nIter_, 1, 100);
        ImGui::SliderFloat("Lambda", &lambda_, 1E-3, 1, "%.3f");
        ImGui::SliderFloat("Mu", &mu_, 1E-3, 1, "%.3f");
        if( ImGui::Button("Compute") )
        {
            if( lambda_ < mu_ )
            {
                TP3_Ex2_ExplicitLaplacianSmoothing surfSmooth(mesh_);
                for( int i = 0 ; i < nIter_ ; i++ )
                {
                    surfSmooth.explicit_smoothing(1, lambda_);
                    surfSmooth.explicit_smoothing(1, -mu_);
                }
                update_mesh();
            }
            else
            {
                std::cerr << "Mu must be greater than lambda.\n"
                          << "No operation has been applied." << std::endl;
            }
        }
    }

    if( ImGui::CollapsingHeader("Desbrun correction") )
    {
        if( ImGui::Button("Compute") )
        {
            pmp::Scalar volumeBeforeSmooth = pmp::volume(mesh_);
            TP3_Ex2_ExplicitLaplacianSmoothing surfSmooth(mesh_);
            surfSmooth.explicit_smoothing(5, 0.5f);
            pmp::Scalar volumeAfterSmooth = pmp::volume(mesh_);
            pmp::Scalar scaleFactor = std::pow(volumeBeforeSmooth/volumeAfterSmooth, 1.0/3.0);
            
            for(auto const& v : mesh_.vertices())
            {
                mesh_.position(v) *= scaleFactor;
            }
            update_mesh();
        }
    }
}