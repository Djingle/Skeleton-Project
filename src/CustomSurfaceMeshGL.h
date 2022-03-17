///
/// \file CustomSurfaceMeshGL.h
/// \brief Header file of CustomSurfaceMeshGL
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 0.2.0
///

#ifndef CUSTOM_SURFACE_MESH_GL_H
#define CUSTOM_SURFACE_MESH_GL_H

#include <string>

#include <pmp/visualization/SurfaceMeshGL.h>

class CustomSurfaceMeshGL : public pmp::SurfaceMeshGL
{
public:
    CustomSurfaceMeshGL();

    ~CustomSurfaceMeshGL();

    ///
    /// \fn void CustomSurfaceMeshGL::load_mesh_off_format(std::string filePath)
    /// \brief Load a mesh from a .off file
    ///
    /// \param filePath Path to .off file
    ///
    void load_mesh_off_format(std::string filePath);

    ///
    /// \fn void CustomSurfaceMeshGL::addRandomVertexColor()
    /// \brief Does things
    ///
    void addRandomVertexColor();
};

#endif // CUSTOM_SURFACE_MESH_GL_H