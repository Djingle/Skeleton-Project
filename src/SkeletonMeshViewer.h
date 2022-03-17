///
/// \file SkeletonMeshViewer.h
/// \brief Header file of SkeletonMeshViewer
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 0.2.0
///

#ifndef TP4_EX1_TOOLS_H
#define TP4_EX1_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

class SkeletonMeshViewer : public pmp::MeshViewer
{
public:
    SkeletonMeshViewer(const char *title,
                       int width, int height,
                       pmp::SurfaceMeshGL &mesh,
                       bool showgui = true);

    ///
    /// \fn void SkeletonMeshViewer::process_imgui()
    ///
    void process_imgui();

private:
};

#endif