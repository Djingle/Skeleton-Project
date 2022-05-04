///
/// \file SkeletonViewer.h
/// \brief Header file of SkeletonViewer
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 1.0.0
///

#ifndef SKELETON_VIEWER_H
#define SKELETON_VIEWER_H

#include <pmp/visualization/MeshViewer.h>
#include <imgui.h>

#include "Skeletizator.h"
#include "imfilebrowser.h"

///
/// \brief Skeleton viewer
///
class SkeletonViewer : public pmp::MeshViewer
{
public:
    ///
    /// \fn SkeletonViewer SkeletonViewer::SkeletonViewer(const char *title, int width, int height, pmp::SurfaceMeshGL &mesh, bool showgui = true);
    /// \brief Load a mesh from a .off file
    ///
    /// \param title Name of window
    /// \param width Width of window
    /// \param quality_speed_tradeoff Value of quality parameter
    /// \param medially_centered_speed_tradeoff Value of medial axis parameter
    /// \param height Height of window
    /// \param showgui Show graphic UI (default : TRUE)
    ///
    SkeletonViewer(const char *title,
                   int width,
                   int height,
                   int quality_speed_tradeoff, 
                   int medially_centered_speed_tradeoff,
                   bool showgui = true);

    ///
    /// \fn void SkeletonViewer::process_imgui()
    /// \brief Process GUI
    ///
    void process_imgui();

    ///
    /// \fn const bool& mesh_displayed()
    /// \brief Return display_mesh_ boolean
    ///
    inline const bool& mesh_displayed() const { return display_mesh_; }

    ///
    /// \fn const bool& skeleton_displayed()
    /// \brief Return display_skeleton_ boolean
    ///
    inline const bool& skeleton_displayed() const { return display_skeleton_; }

    ///
    /// \fn const bool& mesh_colored()
    /// \brief Return color_mesh_ boolean
    ///
    inline const bool& mesh_colored() const { return color_mesh_; }

    ///
    /// \fn const bool& skeleton_colored()
    /// \brief Return color_skeleton_ boolean
    ///
    inline const bool& skeleton_colored() const { return color_skeleton_; }

    ///
    /// \fn double compute_size()
    /// \brief Compute the logical size of the mesh
    ///
    void compute_size();

    ///
    /// \fn void init_ratio()
    /// \brief Computes the ratio between the logical size and the physical size
    ///
    void init_ratio();

    ///
    /// \fn void color_skeleton()
    /// \brief Color the skeleton according to the physical size
    ///
    void color_skeleton();

    ///
    /// \fn void draw(const std::string& draw_mode)
    /// \brief Draw GUI
    ///
    /// \param draw_mode Drawing mode
    ///
    virtual void draw(const std::string& draw_mode) override;

private:
    // Skeletizator
    Skeletizator* skeletizator_;

    // Skeleton mesh
    pmp::SurfaceMeshGL skel_;

    // Scale
    bool size_picked_;
    int selected_axis_ = 0;
    double threshold_ = 0.0;
    double user_size_ = 0.0;
    double x_size_;
    double y_size_;
    double z_size_;
    double ratio_;

    // Display informations
    bool display_mesh_;
    bool display_skeleton_;
    bool color_mesh_;
    bool color_skeleton_;
    bool mesh_loaded_;

    // UI file browser
    ImGui::FileBrowser file_dialog_;
};

#endif