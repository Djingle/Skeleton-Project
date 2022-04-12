///
/// \file SkeletonMeshViewer.cpp
/// \brief Source file of SkeletonMeshViewer
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 0.2.0
///

#include "./SkeletonMeshViewer.h"

#include <pmp/algorithms/SurfaceFeatures.h>

#include <imgui.h>

SkeletonMeshViewer::SkeletonMeshViewer(const char *title,
                                       int width, int height,
                                       pmp::SurfaceMeshGL &mesh,
                                       bool showgui) : pmp::MeshViewer(title,
                                                                       width, height,
                                                                       showgui)
{
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

    if (ImGui::Button("Load Mesh")){}
    if (ImGui::InputDouble("Final size", &size_, 0.01, 0.1)){}
    if (ImGui::Checkbox("Display Mesh", &display_mesh_)){}
    if (ImGui::Checkbox("Display Skeleton", &display_skeleton_)){}
    if (ImGui::Checkbox("Color Mesh", &color_mesh_)){}
    if (ImGui::Checkbox("Color Skeleton", &color_skeleton_)){}
}