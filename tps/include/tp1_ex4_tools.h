#ifndef TP1_EX4_TOOLS_H
#define TP1_EX4_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

class TP1_Ex4_MeshViewer : public pmp::MeshViewer
{
public:
    TP1_Ex4_MeshViewer(const char* title,
                       int width, int height,
                       bool showgui=true);

    TP1_Ex4_MeshViewer(const char* title,
                       int width, int height,
                       const pmp::SurfaceMeshGL& mesh,
                       bool showgui=true);

    void process_imgui();
};

void colorMeshFaces(pmp::SurfaceMesh& mesh,
                    const pmp::Color& color);

void colorMeshVertices(pmp::SurfaceMesh& mesh,
                       const pmp::Color& color);

void colorMeshVerticesRandomHue(pmp::SurfaceMesh& mesh);

#endif // TP1_EX4_TOOLS_H