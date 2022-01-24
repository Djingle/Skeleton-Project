#ifndef CORRECTION_TP4_EX1_TOOLS_H
#define CORRECTION_TP4_EX1_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

class TP4_Ex1_MeshViewer : public pmp::MeshViewer
{
public:
    TP4_Ex1_MeshViewer(const char* title,
                       int width, int height,
                       pmp::SurfaceMeshGL& mesh,
                       bool showgui=true);

    void process_imgui();

private:
    int angle_{50};
};

#endif // CORRECTION_TP4_EX1_TOOLS_H