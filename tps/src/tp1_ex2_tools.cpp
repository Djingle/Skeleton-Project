#include "../include/tp1_ex2_tools.h"

void printHalfEdge(const pmp::SurfaceMesh* const mesh,
                   const pmp::Halfedge&          querryHE,
                   const std::string&            spacePrefix)
{
    std::cout << spacePrefix << "Half-Edge " << querryHE << " (" << mesh->from_vertex(querryHE) << " to " << mesh->to_vertex(querryHE) << ")" << std::endl;
}

void printFace(const pmp::SurfaceMesh* const mesh,
               const pmp::Face&              querryF,
               const std::string&            spacePrefix)
{
    std::cout << spacePrefix << "Face " << querryF << " made of:\n  " << spacePrefix;

    pmp::SurfaceMesh::VertexAroundFaceCirculator vafc = mesh->vertices(querryF);
    for( auto const& nv : vafc )
    {
        std::cout << nv << " ";
    }
    std::cout << std::endl;    
}

void questionA_printVerticesOfHalfEdge(const pmp::SurfaceMesh* const mesh,
                                       const pmp::Halfedge&          querryHE)
{
    /* ! STUDENTS TODO ! */
    // Print the vertices of a querry half-edge
}

void questionA_printVerticesOfOppositeHalfEdge(const pmp::SurfaceMesh* const mesh,
                                               const pmp::Halfedge&          querryHE)
{
    /* ! STUDENTS TODO ! */
    // Print the opposite half-edge of a querry half-edge
}

void questionA_printVerticesOfNextHalfEdge(const pmp::SurfaceMesh* const mesh,
                                           const pmp::Halfedge&          querryHE)
{
    /* ! STUDENTS TODO ! */
    // Print the next half-edge of a querry half-edge
}

void questionA_printVerticesOfPreviousHalfEdge(const pmp::SurfaceMesh* const mesh,
                                               const pmp::Halfedge&          querryHE)
{
    /* ! STUDENTS TODO ! */
    // Print the previous half-edge of a querry half-edge
}

void questionA_printIncidentFaceOfHalfEdge(const pmp::SurfaceMesh* const mesh,
                                           const pmp::Halfedge&          querryHE)
{
    /* ! STUDENTS TODO ! */
    // Print the face attached to a querry half-edge
}

void questionB_printVerticesAroundVertex(const pmp::SurfaceMesh* const mesh,
                                         const pmp::Vertex&            querryV)
{
    /* ! STUDENTS TODO ! */
    // Print the vertices that are neighbours to a querry vertex (use circulators)
}

void questionB_printHalfEdgesAroundVertex(const pmp::SurfaceMesh* const mesh,
                                          const pmp::Vertex&            querryV)
{
    /* ! STUDENTS TODO ! */
    // Print the half-edges that are going from a querry vertex (use circulators)
}

void questionB_printFacesAroundVertex(const pmp::SurfaceMesh* const mesh,
                                      const pmp::Vertex&            querryV)
{
    /* ! STUDENTS TODO ! */
    // Print the faces that contain a querry vertex (use circulators)
}

void questionC_printVerticesAroundFace(const pmp::SurfaceMesh* const mesh,
                                       const pmp::Face&              querryF)
{
    /* ! STUDENTS TODO ! */
    // Print the vertices of a querry face (use circulators)
}

void questionC_printHalfEdgesAroundFace(const pmp::SurfaceMesh* const mesh,
                                        const pmp::Face&              querryF)
{
    /* ! STUDENTS TODO ! */
    // Print the half-edges of a querry face (use circulators)
}

void questionC_printFacesAroundFace(const pmp::SurfaceMesh* const mesh,
                                    const pmp::Face&              querryF)
{
    /* ! STUDENTS TODO ! */
    // Print the faces that are neighbours to a querry face (use circulators)
}