#ifndef CORRECTION_TP1_EX3_TOOLS_H
#define CORRECTION_TP1_EX3_TOOLS_H

#include <pmp/SurfaceMesh.h>

void transformMesh(pmp::SurfaceMesh&        mesh,
                   const pmp::Mat4<float>&  affineTransform);

#endif // CORRECTION_TP1_EX3_TOOLS_H