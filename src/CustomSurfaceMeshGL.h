#ifndef CUSTOM_SURFACE_MESH_GL_H
#define CUSTOM_SURFACE_MESH_GL_H

#include <string>

#include <pmp/visualization/SurfaceMeshGL.h>

class CustomSurfaceMeshGL : public pmp::SurfaceMeshGL
{
public:
    CustomSurfaceMeshGL();

    ~CustomSurfaceMeshGL();

    void load_mesh_off_format(std::string filePath);

    void addRandomVertexColor();
};

#endif // CUSTOM_SURFACE_MESH_GL_H