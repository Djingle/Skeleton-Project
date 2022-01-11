#ifndef TP2_EX6_TOOLS_H
#define TP2_EX6_TOOLS_H

#include <pmp/visualization/MeshViewer.h>
#include <pmp/algorithms/SurfaceGeodesic.h>

class TP2_Ex6_MeshViewer : public pmp::MeshViewer
{
public:
    TP2_Ex6_MeshViewer(const char* title,
                       int width, int height,
                       pmp::SurfaceMeshGL& mesh,
                       bool showgui=true);
    
    ~TP2_Ex6_MeshViewer();

    void process_imgui();

    void mouse(int button, int action, int mods);

private:
    /* ! STUDENTS TODO ! */
    // Add members if required
};

void colorVerticesPerGeodesic(pmp::SurfaceMesh&             mesh
                              /* ! STUDENTS TODO ! */
                              // Fill if required
                              );

#endif // TP2_EX6_TOOLS_H