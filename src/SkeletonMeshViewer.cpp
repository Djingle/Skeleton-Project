///
/// \file SkeletonMeshViewer.cpp
/// \brief Source file of SkeletonMeshViewer
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 0.2.0
///

#include "./SkeletonMeshViewer.h"

#include <pmp/algorithms/SurfaceFeatures.h>

#include <imgui.h>
#include "imfilebrowser.h"

SkeletonMeshViewer::SkeletonMeshViewer(const char *title,
                                       int width, int height,
                                       pmp::SurfaceMeshGL &mesh,
                                       pmp::SurfaceMeshGL &skel,
                                       bool showgui) : pmp::MeshViewer(title, width, height, showgui),
                                                       display_mesh_(true),
                                                       display_skeleton_(true),
                                                       color_mesh_(false),
                                                       color_skeleton_(false),
                                                       size_picked_(false)
{
    // Initiate the file dialog
    file_dialog_.SetTitle("Ouvrir");
    file_dialog_.SetTypeFilters({".off"});

    // Initiate the current mesh
    mesh_ = mesh;
    skel_ = skel;
    pmp::BoundingBox bb = mesh_.bounds();
    set_scene((pmp::vec3)bb.center(), 0.6 * bb.size());

    // Set draw mode
    if (mesh_.n_faces() == 0)
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
    mesh_.set_alpha(0.5);
    
    compute_size();
}

void SkeletonMeshViewer::draw(const std::string &drawMode)
{
    if (size_picked_) color_skeleton();
    // draw mesh
    if (display_mesh_)
        mesh_.draw(projection_matrix_, modelview_matrix_, drawMode);
    if (display_skeleton_)
        skel_.draw(projection_matrix_, modelview_matrix_, "Points", false);
    auto col = skel_.vertex_property<pmp::Color>("v:color");
    for (auto v : skel_.vertices()) {
        std::cout << "color : " << col[v] << std::endl;
    }
}

void SkeletonMeshViewer::compute_size()
{
    pmp::Point x_min(std::numeric_limits<double>::max());
    pmp::Point x_max(-std::numeric_limits<double>::max());
    pmp::Point y_min(std::numeric_limits<double>::max());
    pmp::Point y_max(-std::numeric_limits<double>::max());
    pmp::Point z_min(std::numeric_limits<double>::max());
    pmp::Point z_max(-std::numeric_limits<double>::max());
    for (auto v : mesh_.vertices()) {
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

void SkeletonMeshViewer::init_ratio()
{
    if (size_picked_) {
        if (selected_axis_ == 0) ratio_ = user_size_ / x_size_;
        else if (selected_axis_ == 1) ratio_ = user_size_ / y_size_;
        else if (selected_axis_ == 2) ratio_ = user_size_ / z_size_;
    }
}

void SkeletonMeshViewer::color_skeleton()
{
    auto dist = skel_.vertex_property<float>("distance");
    auto col = skel_.vertex_property<pmp::Color>("v:color");
    for (auto v : skel_.vertices()) {
        double act_dist = (dist[v]*ratio_);
        //std::cout << "dist : " << act_dist << std::endl;
        col[v] = act_dist > 0.5 ? pmp::Color(0.0, 1.0, 0.0) : pmp::Color(1.0, 0.0, 0.0);
        //std::cout << "color : " << col[v] << std::endl;
    }
}

void SkeletonMeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    // Set the file browser open
    if (ImGui::Button("Load Mesh"))
    {
        file_dialog_.Open();
    }

    // Select size of the final object
    if (ImGui::InputDouble("Final size", &user_size_, 0.01, 0.1))
    {
        size_picked_ = true;
        init_ratio();
        color_skeleton();
        std::cout << "x_size_ :" << x_size_ << " y_size_ :" << y_size_ << " z_size_ :" << z_size_ << std::endl;
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
        std::cout << "Mesh display : " << display_mesh_ << std::endl;
    }

    // Toggle skeleton display
    if (ImGui::Checkbox("Display Skeleton", &display_skeleton_))
    {
        std::cout << "Skeleton display : " << display_skeleton_ << std::endl;
    }

    // Toggle mesh coloration
    if (ImGui::Checkbox("Color Mesh", &color_mesh_))
    {
        std::cout << "Mesh color : " << color_mesh_ << std::endl;
    }

    // Toggle skeleton coloration
    if (ImGui::Checkbox("Color Skeleton", &color_skeleton_))
    {
        std::cout << "Skeleton color : " << color_skeleton_ << std::endl;
    }

    // Display file browser
    file_dialog_.Display();
    if (file_dialog_.HasSelected())
    {
        // Load selected mesh
        std::string imput_path = file_dialog_.GetSelected();
        pmp::SurfaceMeshGL imput_mesh;
        imput_mesh.read(imput_path);
        mesh_ = imput_mesh;
        pmp::BoundingBox bb = mesh_.bounds();
        set_scene((pmp::vec3)bb.center(), 0.6 * bb.size());
        update_mesh();
        file_dialog_.ClearSelected();
    }
}
