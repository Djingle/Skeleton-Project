#ifndef TP1_EX3_TOOLS_H
#define TP1_EX3_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

class TP1_Ex3_MeshViewer : public pmp::MeshViewer
{
public:
    TP1_Ex3_MeshViewer(const char* title,
                       int width, int height,
                       bool showgui=true);

    TP1_Ex3_MeshViewer(const char* title,
                       int width, int height,
                       const pmp::SurfaceMeshGL& mesh,
                       bool showgui=true);

    void process_imgui();
};

void colorMeshVertices(pmp::SurfaceMesh& mesh,
                       const pmp::Color& color);

void colorMeshFaces(pmp::SurfaceMesh& mesh,
                    const pmp::Color& color);

#endif // TP1_EX3_TOOLS_H