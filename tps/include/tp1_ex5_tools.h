#ifndef TP1_EX5_TOOLS_H
#define TP1_EX5_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

class TP1_Ex5_MeshViewer : public pmp::MeshViewer
{
public:
    TP1_Ex5_MeshViewer(const char* title,
                       int width, int height,
                       std::vector<pmp::SurfaceMeshGL*>&    meshes,
                       std::vector<std::string>&            meshesName,
                       bool showgui=true);

    void process_imgui();

private:
    std::vector<pmp::SurfaceMeshGL*>& meshes_;
    std::vector<std::string>&               meshesName_;
    int                                     selectedMeshId_;
};

#endif // TP1_EX5_TOOLS_H