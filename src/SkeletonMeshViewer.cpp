///
/// \file SkeletonMeshViewer.cpp
/// \brief Source file of SkeletonMeshViewer
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 0.2.0
///

#include "./SkeletonMeshViewer.h"

#include <pmp/algorithms/SurfaceFeatures.h>
#include <pmp/algorithms/SurfaceTriangulation.h>

#include <imgui.h>

SkeletonMeshViewer::SkeletonMeshViewer(const char *title,
                                       int width, int height,
                                       pmp::SurfaceMeshGL &mesh,
                                       bool showgui) : pmp::MeshViewer(title,
                                                                       width, height,
                                                                       showgui)
{
    mesh_ = mesh;
    pmp::BoundingBox bb = mesh_.bounds();
    set_scene((pmp::vec3)bb.center(), 0.6 * bb.size());

    // Set draw mode
    if (mesh_.n_faces() == 0)
    {
        set_draw_mode("Points");
    }
    else
    {
        set_draw_mode("Hidden Line");
    }

    // Compute face & vertex normals, update face indices
    update_mesh();

    // Set viewer angle parameter
    mesh_.set_crease_angle(0);
}

void SkeletonMeshViewer::process_imgui()
{

    if (!mesh_.is_triangle_mesh())
    {
        auto triangle = pmp::SurfaceTriangulation(mesh_);
        triangle.triangulate();
        update_mesh();
    }
    pmp::MeshViewer::process_imgui();
}