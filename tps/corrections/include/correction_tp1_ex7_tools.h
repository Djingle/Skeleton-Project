#ifndef CORRECTION_TP1_EX7_TOOLS_H
#define CORRECTION_TP1_EX7_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

//! Texture coordinate type
typedef pmp::Vector<float, 2> TexCoord;

class TP1_Ex7_MeshViewer : public pmp::MeshViewer
{
public:
    TP1_Ex7_MeshViewer(const char* title,
                       int width, int height,
                       pmp::SurfaceMeshGL& mesh,
                       bool showgui=true);
    
    void process_imgui();
};

void labelVerticesPerConnectedComponent(pmp::SurfaceMesh&  mesh,
                                        const std::string& storagePropertyName);

void vertex_property_to_color(pmp::SurfaceMeshGL&   mesh,
                             const std::string&     propertyName);

#endif // CORRECTION_TP1_EX7_TOOLS_H