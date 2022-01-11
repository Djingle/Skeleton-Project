#ifndef CORRECTION_TP1_EX6_TOOLS_H
#define CORRECTION_TP1_EX6_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

//! Texture coordinate type
typedef pmp::Vector<float, 2> TexCoord;

class TP1_Ex6_MeshViewer : public pmp::MeshViewer
{
public:
    TP1_Ex6_MeshViewer(const char* title,
                       int width, int height,
                       pmp::SurfaceMeshGL& mesh,
                       bool showgui=true);

    void process_imgui();
};

void colorVerticesPerValence(pmp::SurfaceMeshGL &mesh);

void vertex_valence_to_color(pmp::SurfaceMeshGL &mesh);

void colorFacesPerArea(pmp::SurfaceMeshGL &mesh);

void face_area_to_color(pmp::SurfaceMeshGL &mesh);

#endif // CORRECTION_TP1_EX6_TOOLS_H