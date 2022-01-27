#ifndef CORRECTION_TP1_EX4_TOOLS_H
#define CORRECTION_TP1_EX4_TOOLS_H

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

/*! \brief Convert HSV to RGB color space
  
  Converts a given set of HSV values `h', `s', `v' into RGB
  coordinates. The output RGB values are in the range [0, 1], and
  the input HSV values are in the ranges h = [0, 360], and s, v =
  [0, 1], respectively.
  
  \param fR Red component, used as output, range: [0, 1]
  \param fG Green component, used as output, range: [0, 1]
  \param fB Blue component, used as output, range: [0, 1]
  \param fH Hue component, used as input, range: [0, 360]
  \param fS Saturation component, used as input, range: [0, 1]
  \param fV Value component, used as input, range: [0, 1]
  
  TAKEN FROM https://gist.github.com/fairlight1337/4935ae72bcbcc1ba5c72
*/
void HSVtoRGB(float& fR, float& fG, float& fB, float& fH, float& fS, float& fV);

void colorMeshFaces(pmp::SurfaceMesh& mesh,
                    const pmp::Color& color);

void colorMeshVertices(pmp::SurfaceMesh& mesh,
                       const pmp::Color& color);

void colorMeshVerticesRandomHue(pmp::SurfaceMesh& mesh);

#endif // CORRECTION_TP1_EX4_TOOLS_H