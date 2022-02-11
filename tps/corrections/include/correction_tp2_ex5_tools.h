#ifndef CORRECTION_TP2_EX5_TOOLS_H
#define CORRECTION_TP2_EX5_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

class TP2_Ex5_MeshViewer : public pmp::MeshViewer
{
public:
    TP2_Ex5_MeshViewer(const char* title,
                       int width, int height,
                       pmp::SurfaceMeshGL& mesh,
                       bool showgui=true);
    
    void process_imgui();
};

#endif // CORRECTION_TP2_EX5_TOOLS_H