///
/// \file SkeletonViewer.cpp
/// \brief Source file of SkeletonViewer
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 1.0.0
///

#include <pmp/algorithms/SurfaceFeatures.h>
#include <imgui.h>

#include "SkeletonViewer.h"

SkeletonViewer::SkeletonViewer(const char *title,
                               int width,
                               int height,
                               int quality_speed_tradeoff, 
                               int medially_centered_speed_tradeoff,
                               bool showgui) : pmp::MeshViewer(title, width, height, showgui),
                                                               display_mesh_(true),
                                                               display_skeleton_(true),
                                                               color_mesh_(false),
                                                               color_skeleton_(false)
{
    // Initiate the file dialog
    file_dialog_.SetTitle("Ouvrir");
    file_dialog_.SetTypeFilters({".off"});

    // Init skeletizator
    Skeletizator* temp_sk = new Skeletizator(quality_speed_tradeoff,
                                             medially_centered_speed_tradeoff);

    skeletizator_ = temp_sk;

    mesh_loaded_ = false;
}

void SkeletonViewer::draw(const std::string &drawMode)
{
    // Draw mesh
    if (display_mesh_)
        mesh_.draw(projection_matrix_, modelview_matrix_, drawMode);

    // Draw skeleton
    if (display_skeleton_)
        skel_.draw(projection_matrix_, modelview_matrix_, "Points", false);
}

void SkeletonViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    // Set the file browser open
    if (ImGui::Button("Load Mesh"))
    {
        file_dialog_.Open();
    }

    if(mesh_loaded_)
    {
        // Select size of the final object
        if (ImGui::InputDouble("Final size", &size_, 0.01, 0.1))
        {
        }

        // Select dimension on which the final size will be applied
        if (ImGui::BeginCombo("Dimension", selected_dimension_))
        {
            bool _x, _y, _z;
            const char *dimensions[] = {"X", "Y", "Z"};

            if (ImGui::Selectable("X", &_x))
            {
                selected_dimension_ = dimensions[0];
            }

            if (ImGui::Selectable("Y", &_y))
            {
                selected_dimension_ = dimensions[1];
            }

            if (ImGui::Selectable("Z", &_z))
            {
                selected_dimension_ = dimensions[2];
            }

            ImGui::EndCombo();
        }

        // Toggle mesh display
        if (ImGui::Checkbox("Display Mesh", &display_mesh_))
        {
        }

        // Toggle skeleton display
        if (ImGui::Checkbox("Display Skeleton", &display_skeleton_))
        {
        }

        // Toggle mesh coloration
        if (ImGui::Checkbox("Color Mesh", &color_mesh_))
        {
        }

        // Toggle skeleton coloration
        if (ImGui::Checkbox("Color Skeleton", &color_skeleton_))
        {
        }
    }

    // Display file browser
    file_dialog_.Display();
    
    if (file_dialog_.HasSelected())
    {
        // Get .off file path
        std::string input_path = file_dialog_.GetSelected();

        // Load PMP mesh
        mesh_.read(input_path);
        mesh_loaded_ = true;

        // Compute skeleton
        skeletizator_->init(input_path);
        skeletizator_->compute_skeleton();
        skeletizator_->convert_to_pmp_mesh();
        skel_ = *(skeletizator_->PMP_skel_);

        // Set scene
        pmp::BoundingBox bb = mesh_.bounds();
        set_scene((pmp::vec3)bb.center(), 0.6 * bb.size());
        
        // Set viewer angle parameter
        mesh_.set_crease_angle(0);
        mesh_.set_alpha(0.5);

        update_mesh();

        // Clear UI
        file_dialog_.ClearSelected();
    }
}