///
/// \file SkeletonMeshViewer.h
/// \brief Header file of SkeletonMeshViewer
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 0.2.0
///

#ifndef TP4_EX1_TOOLS_H
#define TP4_EX1_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

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
                       bool showgui = true);

    ///
    /// \fn void SkeletonMeshViewer::process_imgui()
    ///
    void process_imgui();

    inline const bool& mesh_displayed() const { return display_mesh_; }
    inline const bool& skeleton_displayed() const { return display_skeleton_; }
    inline const bool& mesh_colored() const { return color_mesh_; }
    inline const bool& skeleton_colored() const { return color_skeleton_; }

private:
    bool display_mesh_;
    bool display_skeleton_;
    bool color_mesh_;
    bool color_skeleton_;
    double size_;
};

#endif