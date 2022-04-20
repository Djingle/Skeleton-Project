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

protected:
    pmp::SurfaceMeshGL skel_;   //!< the mesh
    
private:

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