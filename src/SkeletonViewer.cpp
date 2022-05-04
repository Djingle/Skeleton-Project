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
    if(display_mesh_)
        mesh_.draw(projection_matrix_, modelview_matrix_, drawMode);

    // Draw skeleton
    if(display_skeleton_)
        skel_.draw(projection_matrix_, modelview_matrix_, "Points", false);
}

void SkeletonViewer::compute_size()
{
    pmp::Point x_min(std::numeric_limits<double>::max());
    pmp::Point x_max(std::numeric_limits<double>::min());
    pmp::Point y_min(std::numeric_limits<double>::max());
    pmp::Point y_max(std::numeric_limits<double>::min());
    pmp::Point z_min(std::numeric_limits<double>::max());
    pmp::Point z_max(std::numeric_limits<double>::min());

    // Get the min and max values in each dimension
    for(auto v : mesh_.vertices())
    {
        if (mesh_.position(v)[0] < x_min[0])
            x_min = mesh_.position(v);

        if (mesh_.position(v)[0] > x_max[0])
            x_max = mesh_.position(v);

        if (mesh_.position(v)[1] < y_min[1])
            y_min = mesh_.position(v);

        if (mesh_.position(v)[1] > y_max[1])
            y_max = mesh_.position(v);

        if (mesh_.position(v)[2] < z_min[2])
            z_min = mesh_.position(v);

        if (mesh_.position(v)[2] > z_max[2])
            z_max = mesh_.position(v);
    }

    x_size_ = distance(x_min, x_max);
    y_size_ = distance(y_min, y_max);
    z_size_ = distance(z_min, z_max);
}

void SkeletonViewer::init_ratio()
{
    if(size_picked_)
    {
        switch(selected_axis_)
        {
            case 0:
                ratio_ = user_size_/x_size_;
                break;
            
            case 1:
                ratio_ = user_size_/y_size_;
                break;

            case 2:
                ratio_ = user_size_/z_size_;
                break;

            default:
                std::cout << "Invalid selected axis, ratio is 1:1" << std::endl;
                ratio = 1.0;
                break;
        }
    }
}

void SkeletonMeshViewer::color_skeleton()
{
    auto dist = skel_.vertex_property<float>("distance");
    auto col = skel_.vertex_property<pmp::Color>("v:color");

    for(auto v : skel_.vertices())
    {
        double act_dist = (dist[v]*ratio_);
        col[v] = act_dist > 0.5 ? pmp::Color(0.0, 1.0, 0.0) : pmp::Color(1.0, 0.0, 0.0);
    }
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
        if (ImGui::InputDouble("Final size", &user_size_, 0.01, 0.1))
        {
            size_picked_ = true;
            init_ratio();
            color_skeleton();
        }

        // Select dimension on which the final size will be applied
        if (ImGui::BeginCombo("Dimension", "X"))
        {
            bool _x, _y, _z;

            if (ImGui::Selectable("X", &_x))
            {
                selected_axis_ = 0;
                init_ratio();
            }
            if (ImGui::Selectable("Y", &_y))
            {
                selected_axis_ = 1;
                init_ratio();
            }
            if (ImGui::Selectable("Z", &_z))
            {
                selected_axis_ = 2;
                init_ratio();
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
        compute_size();
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