#ifndef TP3_EX2_TOOLS_H
#define TP3_EX2_TOOLS_H

#include <pmp/visualization/MeshViewer.h>
#include <pmp/algorithms/SurfaceSmoothing.h>

class TP3_Ex2_ExplicitLaplacianSmoothing : public pmp::SurfaceSmoothing
{
public:
    TP3_Ex2_ExplicitLaplacianSmoothing(pmp::SurfaceMesh& mesh) : pmp::SurfaceSmoothing(mesh)
    {
        // Nothing to do
    }

    void explicit_smoothing(unsigned int    iters,
                            float           lambda,
                            bool            use_uniform_laplace=false)
    {
        /* ! STUDENTS TODO ! */
    }
};

class TP3_Ex2_MeshViewer : public pmp::MeshViewer
{
public:
    TP3_Ex2_MeshViewer(const char* title,
                       int width, int height,
                       pmp::SurfaceMeshGL& mesh,
                       bool showgui=true);

    void process_imgui();

private:
    /* ! STUDENTS TODO ! */
    // Complete if necessary
};

#endif // TP3_EX2_TOOLS_H