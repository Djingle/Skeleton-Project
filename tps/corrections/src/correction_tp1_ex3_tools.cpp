#include "../include/correction_tp1_ex3_tools.h"

void transformMesh(pmp::SurfaceMesh&        mesh,
                   const pmp::Mat4<float>&  affineTransform)
{
    for(auto const& v : mesh.vertices())
    {
        mesh.position(v) = pmp::affine_transform(affineTransform, mesh.position(v));
    }
}