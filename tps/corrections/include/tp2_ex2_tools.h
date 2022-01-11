#ifndef TP2_EX2_TOOLS_H
#define TP2_EX2_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

class TP2_Ex2_MeshViewer : public pmp::MeshViewer
{
public:
    TP2_Ex2_MeshViewer(const char* title,
                       int width, int height,
                       pmp::SurfaceMeshGL& mesh,
                       bool showgui=true);
    
    void process_imgui();
};

void colorBorderFaces(pmp::SurfaceMesh& mesh);

void fillHoles(pmp::SurfaceMesh& mesh);

void labelVerticesPerConnectedComponent(pmp::SurfaceMesh&       mesh,
                                        const std::string&      ccLabelStoragePropertyName,
                                        std::vector< size_t >&  outNVerticesInCc);

void removeSmallConnectedComponents(pmp::SurfaceMesh&       mesh,
                                    const std::string&      ccLabelStoragePropertyName,
                                    std::vector< size_t >&  nVerticesInCc,
                                    size_t                  nVerticesMin = 0);

#endif // TP2_EX2_TOOLS_H