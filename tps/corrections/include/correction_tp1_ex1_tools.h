#ifndef CORRECTION_TP1_EX1_TOOLS_H
#define CORRECTION_TP1_EX1_TOOLS_H

#include <pmp/SurfaceMesh.h>

void questionA_printGeneralInformationAboutMesh(const pmp::SurfaceMesh&   mesh,
                                                const std::string&        meshName);

void questionB_printMeshVerticesV1(const pmp::SurfaceMesh&    mesh,
                                   size_t                     nVerticesToPrint=0);

void questionB_printMeshVerticesV2(const pmp::SurfaceMesh&    mesh,
                                   size_t                     nVerticesToPrint=0);

void questionB_printMeshVerticesV3(const pmp::SurfaceMesh&    mesh,
                                   size_t                     nVerticesToPrint=0);

void questionC_printMeshHalfEdges(const pmp::SurfaceMesh&   mesh,
                                  size_t                    nHalfEdgesToPrint=0);

void questionD_printMeshEdges(const pmp::SurfaceMesh&   mesh,
                              size_t                    nEdgesToPrint=0);

void questionE_printMeshFaces(const pmp::SurfaceMesh&   mesh,
                              size_t                    nFacesToPrint=0);

#endif // CORRECTION_TP1_EX1_TOOLS_H