#ifndef CORRECTION_TP2_EX1_TOOLS_H
#define CORRECTION_TP2_EX1_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

class TP2_Ex1_MeshViewer : public pmp::MeshViewer
{
public:
    TP2_Ex1_MeshViewer(const char* title,
                       int width, int height,
                       pmp::SurfaceMeshGL& mesh,
                       bool showgui=true);
    
    void process_imgui();
};

void colorNonTriangularFaces(pmp::SurfaceMesh& mesh);

#endif // CORRECTION_TP2_EX1_TOOLS_H