#ifndef TP2_EX3_TOOLS_H
#define TP2_EX3_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

class TP2_Ex3_MeshViewer : public pmp::MeshViewer
{
public:
    TP2_Ex3_MeshViewer(const char* title,
                       int width, int height,
                       pmp::SurfaceMeshGL& mesh,
                       bool showgui=true);
    
    void process_imgui();
};

bool isWatertight(const pmp::SurfaceMesh& mesh);

void colorVerticesPerManifoldness(pmp::SurfaceMesh& mesh);

#endif // TP2_EX3_TOOLS_H