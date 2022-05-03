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
#include <iostream>

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
    /// \param height Height of window
    /// \param showgui Show graphic UI (default : TRUE)
    ///
    SkeletonViewer(const char *title,
                   int width,
                   int height,
                   bool showgui = true);

    ///
    /// \fn void SkeletonViewer::process_imgui()
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

private:
    Skeletizator skeltizator_;
    pmp::SurfaceMeshGL skel_;   // Skeleton mesh
    const char * selected_dimension_; // Defines the dimension on which size is applied
    
    // Display informations
    bool display_mesh_;
    bool display_skeleton_;
    bool color_mesh_;
    bool color_skeleton_;

    double size_; // Size of the final object
    ImGui::FileBrowser file_dialog_;
};

#endif