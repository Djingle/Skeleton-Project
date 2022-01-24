#include "../include/tp3_ex1_tools.h"

#include <pmp/algorithms/SurfaceSmoothing.h>
#include <pmp/algorithms/SurfaceFairing.h>

#include <imgui.h>

TP3_Ex1_MeshViewer::TP3_Ex1_MeshViewer(const char* title,
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

void TP3_Ex1_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    if( ImGui::CollapsingHeader("Explicit Laplacian") )
    {
        ImGui::SliderInt("Niter", &explicitLaplacianNIter_, 1, 100);
        ImGui::Checkbox("Use uniform weights", &explicitLaplacianUniformWeights_);
        if( ImGui::Button("Compute") )
        {
            pmp::SurfaceSmoothing surfSmooth(mesh_);
            surfSmooth.explicit_smoothing(explicitLaplacianNIter_);
            update_mesh();
        }
    }

    if( ImGui::CollapsingHeader("Implicit Laplacian") )
    {
        ImGui::SliderFloat("TimeStep", &implicitLaplacianTimeStep_, 1E-4, 1E-1, "%.5f");
        ImGui::Checkbox("Use uniform weights", &implicitLaplacianUniformWeights_);
        if( ImGui::Button("Compute") )
        {
            pmp::SurfaceSmoothing surfSmooth(mesh_);
            surfSmooth.implicit_smoothing(implicitLaplacianTimeStep_, implicitLaplacianUniformWeights_);
            update_mesh();
        }
    }
    if( ImGui::CollapsingHeader("Fairing") )
    {
        ImGui::SliderInt("K", &fairK_, 1, 100);
        if( ImGui::Button("Compute") )
        {
            pmp::SurfaceFairing surfFair(mesh_);
            surfFair.fair(fairK_);
            update_mesh();
        }
    }
}