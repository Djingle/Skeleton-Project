#ifndef TP1_EX2_TOOLS_H
#define TP1_EX2_TOOLS_H

#include <pmp/SurfaceMesh.h>

void printHalfEdge(const pmp::SurfaceMesh* const mesh,
                   const pmp::Halfedge&          querryHE,
                   const std::string&            spacePrefix);

void printFace(const pmp::SurfaceMesh* const mesh,
               const pmp::Face&              querryF,
               const std::string&            spacePrefix);

void questionA_printVerticesOfHalfEdge(const pmp::SurfaceMesh* const mesh,
                                       const pmp::Halfedge&          querryHE);

void questionA_printIncidentFaceOfHalfEdge(const pmp::SurfaceMesh* const mesh,
                                           const pmp::Halfedge&          querryHE);

void questionA_printVerticesOfOppositeHalfEdge(const pmp::SurfaceMesh* const mesh,
                                               const pmp::Halfedge&          querryHE);

void questionA_printVerticesOfNextHalfEdge(const pmp::SurfaceMesh* const mesh,
                                           const pmp::Halfedge&          querryHE);

void questionA_printVerticesOfPreviousHalfEdge(const pmp::SurfaceMesh* const mesh,
                                               const pmp::Halfedge&          querryHE);

void questionB_printVerticesAroundVertex(const pmp::SurfaceMesh* const mesh,
                                         const pmp::Vertex&            querryV);

void questionB_printHalfEdgesAroundVertex(const pmp::SurfaceMesh* const mesh,
                                          const pmp::Vertex&            querryV);

void questionB_printFacesAroundVertex(const pmp::SurfaceMesh* const mesh,
                                      const pmp::Vertex&            querryV);

void questionC_printVerticesAroundFace(const pmp::SurfaceMesh* const mesh,
                                       const pmp::Face&              querryF);

void questionC_printHalfEdgesAroundFace(const pmp::SurfaceMesh* const mesh,
                                        const pmp::Face&              querryF);

void questionC_printFacesAroundFace(const pmp::SurfaceMesh* const mesh,
                                    const pmp::Face&              querryF);

#endif // TP1_EX2_TOOLS_H