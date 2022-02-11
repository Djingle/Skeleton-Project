#ifndef CORRECTION_TP3_EX1_TOOLS_H
#define CORRECTION_TP3_EX1_TOOLS_H

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
    bool        explicitLaplacianUniformWeights_{false};
    int         explicitLaplacianNIter_{1};
    pmp::Scalar implicitLaplacianTimeStep_{1E-4};
    bool        implicitLaplacianUniformWeights_{false};
    int         fairK_{2};
};

#endif // CORRECTION_TP3_EX1_TOOLS_H