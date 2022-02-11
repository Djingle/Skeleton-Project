#ifndef CORRECTION_TP2_EX4_TOOLS_H
#define CORRECTION_TP2_EX4_TOOLS_H

#include <pmp/SurfaceMesh.h>

void printBoundingBoxCoords(pmp::SurfaceMesh& mesh);
void printBoundingBoxSize(pmp::SurfaceMesh& mesh);
void printBoundingBoxDiag(pmp::SurfaceMesh& mesh);
void printMeshTotalArea(pmp::SurfaceMesh& mesh);
void printMeshVerticesCentroid(pmp::SurfaceMesh& mesh);
void printMeshVolume(pmp::SurfaceMesh& mesh);
void printEulerNumberAndGenus(pmp::SurfaceMesh& mesh);

#endif // CORRECTION_TP2_EX4_TOOLS_H