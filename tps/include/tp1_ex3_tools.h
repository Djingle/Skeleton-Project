#ifndef TP1_EX3_TOOLS_H
#define TP1_EX3_TOOLS_H

#include <pmp/SurfaceMesh.h>

void transformMesh(pmp::SurfaceMesh&        mesh,
                   const pmp::Mat4<float>&  affineTransform);

#endif // TP1_EX3_TOOLS_H