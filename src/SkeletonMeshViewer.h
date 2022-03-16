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

    void process_imgui();

private:
};

#endif