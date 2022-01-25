#ifndef TP3_EX1_TOOLS_H
#define TP3_EX1_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

class TP3_Ex1_MeshViewer : public pmp::MeshViewer
{
public:
    TP3_Ex1_MeshViewer(const char* title,
                       int width, int height,
                       pmp::SurfaceMeshGL& mesh,
                       bool showgui=true);

    void process_imgui();

private:
    /* ! STUDENTS TODO ! */
    // Complete if necessary
};

#endif // TP3_EX1_TOOLS_H