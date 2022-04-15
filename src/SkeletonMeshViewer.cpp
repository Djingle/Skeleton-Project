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
                                       bool showgui) : pmp::MeshViewer(title,
                                                                       width, height,
                                                                       showgui)
{
    // Initiate the file dialog
    file_dialog_.SetTitle("Ouvrir");
    file_dialog_.SetTypeFilters({".off"});

    //strcpy(selected_dimension_, "Select a Dimension");

    mesh_ = mesh;
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
}

void SkeletonMeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    if (ImGui::Button("Load Mesh")){
        file_dialog_.Open();
    }
    if (ImGui::InputDouble("Final size", &size_, 0.01, 0.1)){

    }
    if (ImGui::BeginCombo("Dimension", selected_dimension_)) {
        bool _x, _y, _z;
        const char * dimensions[] = {"X", "Y", "Z"};
        
        if (ImGui::Selectable("X", &_x)) {
            selected_dimension_ = dimensions[0];
        }
        if (ImGui::Selectable("Y", &_y)) {
            selected_dimension_ = dimensions[1];
        }
        if (ImGui::Selectable("Z", &_z)) {
            selected_dimension_ = dimensions[2];
        }
        ImGui::EndCombo();
    }
    if (ImGui::Checkbox("Display Mesh", &display_mesh_)){
        std::cout << "Mesh display : " << display_mesh_ << std::endl;
    }
    if (ImGui::Checkbox("Display Skeleton", &display_skeleton_)){
        std::cout << "Skeleton display : " << display_skeleton_ << std::endl;
    }
    if (ImGui::Checkbox("Color Mesh", &color_mesh_)){
        std::cout << "Mesh color : " << color_mesh_ << std::endl;
    }
    if (ImGui::Checkbox("Color Skeleton", &color_skeleton_)){
        std::cout << "Skeleton color : " << color_skeleton_ << std::endl;
    }
    file_dialog_.Display();
    if (file_dialog_.HasSelected()) {
        std::string imput_path = file_dialog_.GetSelected();
        pmp::SurfaceMeshGL imput_mesh;
        std::cout << "Selected filename : " << file_dialog_.GetSelected() << std::endl;
        imput_mesh.read(imput_path);
        mesh_ = imput_mesh;
        pmp::BoundingBox bb = mesh_.bounds();
        set_scene((pmp::vec3)bb.center(), 0.6 * bb.size());
        update_mesh();
        file_dialog_.ClearSelected();
    }
}