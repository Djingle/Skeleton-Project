#include "../include/tp1_ex5_tools.h"

#include <random>

#include <imgui.h>

TP1_Ex5_MeshViewer::TP1_Ex5_MeshViewer(const char* title,
                                        int width, int height,
                                        std::vector<pmp::SurfaceMeshGL*>&  meshes,
                                        std::vector<std::string>&          meshesName,
                                        bool showgui) : pmp::MeshViewer(title,
                                                                        width, height,
                                                                        showgui),
                                                                        meshes_(meshes),
                                                                        meshesName_(meshesName),
                                                                        selectedMeshId_(0)
{
    assert( !meshes.empty() );
    mesh_ = *(meshes[selectedMeshId_]);

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

void TP1_Ex5_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    if( ImGui::BeginCombo("Displayed mesh", meshesName_.at(0).c_str()) )
    {
        for(size_t i = 0; i < meshesName_.size() ; i++ )
        {
            const bool is_selected = ( selectedMeshId_ == i );

            if( ImGui::Selectable(meshesName_[i].c_str(), is_selected) )
            {
                selectedMeshId_ = i;
            }

            // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
            if( is_selected )
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();

        // Now set mesh_ to be the selected mesh
        mesh_ = *(meshes_[selectedMeshId_]);
        update_mesh();
    }
}