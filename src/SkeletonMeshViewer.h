///
/// \file SkeletonMeshViewer.h
/// \brief Header file of SkeletonMeshViewer
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 0.2.0
///

#ifndef TP4_EX1_TOOLS_H
#define TP4_EX1_TOOLS_H

#include <pmp/visualization/MeshViewer.h>
#include <imgui.h>
#include "imfilebrowser.h"

///
/// \brief Mesh and skeleton viewer
///
class SkeletonMeshViewer : public pmp::MeshViewer
{
public:
    ///
    /// \fn SkeletonMeshViewer SkeletonMeshViewer::SkeletonMeshViewer(const char *title, int width, int height, pmp::SurfaceMeshGL &mesh, bool showgui = true);
    /// \brief Load a mesh from a .off file
    ///
    /// \param title Name of window
    /// \param width Width of window
    /// \param height Height of window
    /// \param mesh Mesh to display
    /// \param showgui Show graphic UI (default : TRUE)
    ///
    SkeletonMeshViewer(const char *title,
                       int width, int height,
                       pmp::SurfaceMeshGL &mesh,
                       pmp::SurfaceMeshGL &skel,
                       bool showgui = true);

    ///
    /// \fn void SkeletonMeshViewer::process_imgui()
    /// \brief Renders GUI
    ///
    void process_imgui();

    ///
    /// \fn const bool& mesh_displayed()
    /// \brief display_mesh_ getter
    ///
    inline const bool& mesh_displayed() const { return display_mesh_; }
    ///
    /// \fn const bool& skeleton_displayed()
    /// \brief display_skeleton_ getter
    ///
    inline const bool& skeleton_displayed() const { return display_skeleton_; }
    ///
    /// \fn const bool& mesh_colored()
    /// \brief color_mesh_ getter
    ///
    inline const bool& mesh_colored() const { return color_mesh_; }
    ///
    /// \fn const bool& skeleton_colored()
    /// \brief color_skeleton_ getter
    ///
    inline const bool& skeleton_colored() const { return color_skeleton_; }

    virtual void draw(const std::string& draw_mode) override;


    /// \fn double compute_size(int axis)
    /// \brief computes the logical size of the mesh
    void compute_size();

    /// \fn void init_ratio()
    /// \brief computes the ratio between the logical size and the physical size
    void init_ratio();

    /// \fn void color_skeleton()
    /// \brief colors the skeleton according to the physical size
    void color_skeleton();

protected:
    pmp::SurfaceMeshGL skel_;   //!< the mesh
    
private:

    int selected_axis_ = 0; // Defines the dimension on which size is applied

    double max_dist_, min_dist_;
    
    // Display informations
    bool display_mesh_;
    bool display_skeleton_;
    bool color_mesh_;
    bool color_skeleton_;
    bool size_picked_;

    double user_size_, x_size_, y_size_, z_size_;
    double ratio_;
    ImGui::FileBrowser file_dialog_;
};

#endif
