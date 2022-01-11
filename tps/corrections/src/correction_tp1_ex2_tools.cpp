#include "../include/correction_tp1_ex2_tools.h"

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
    std::cout << "Source vertex of half-Edge " << querryHE << ":\n"
              << "------------------------------\n"
              << mesh->from_vertex(querryHE) << std::endl;
    std::cout << "Target vertex of half-Edge " << querryHE << ":\n"
              << "------------------------------\n"
              << mesh->to_vertex(querryHE) << std::endl;
}

void questionA_printVerticesOfOppositeHalfEdge(const pmp::SurfaceMesh* const mesh,
                                               const pmp::Halfedge&          querryHE)
{
    pmp::Halfedge oppositeHE = mesh->opposite_halfedge(querryHE);

    std::cout << "Opposite half-edge of " << querryHE << ":\n"
              << "-------------------------" << std::endl;
    printHalfEdge(mesh, oppositeHE, "  ");
}

void questionA_printVerticesOfNextHalfEdge(const pmp::SurfaceMesh* const mesh,
                                           const pmp::Halfedge&          querryHE)
{
    pmp::Halfedge nextHE = mesh->next_halfedge(querryHE);

    std::cout << "Next half-edge of " << querryHE << ":\n"
              << "---------------------" << std::endl;
    printHalfEdge(mesh, nextHE, "  ");
}

void questionA_printVerticesOfPreviousHalfEdge(const pmp::SurfaceMesh* const mesh,
                                               const pmp::Halfedge&          querryHE)
{
    pmp::Halfedge prevHE = mesh->next_halfedge(querryHE);

    std::cout << "Previous half-edge of " << querryHE << ":\n"
              << "-------------------------" << std::endl;
    printHalfEdge(mesh, prevHE, "  ");
}

void questionA_printIncidentFaceOfHalfEdge(const pmp::SurfaceMesh* const mesh,
                                           const pmp::Halfedge&          querryHE)
{
    std::cout << "Incident face of half-Edge " << querryHE << ":\n"
              << "------------------------------" << std::endl;
    printFace(mesh, mesh->face(querryHE), "  ");
}

void questionB_printVerticesAroundVertex(const pmp::SurfaceMesh* const mesh,
                                         const pmp::Vertex&            querryV)
{
    std::cout << "Vertices around vertex " << querryV << ":\n"
              << "--------------------------" << std::endl;

    pmp::SurfaceMesh::VertexAroundVertexCirculator vavc(mesh, querryV);
    for( auto const& nv : vavc )
    {
        std::cout << "  Vertex " << nv << std::endl;
    }
}

void questionB_printHalfEdgesAroundVertex(const pmp::SurfaceMesh* const mesh,
                                          const pmp::Vertex&            querryV)
{
    std::cout << "Half-Edges around vertex " << querryV << ":\n"
              << "----------------------------" << std::endl;

    pmp::SurfaceMesh::HalfedgeAroundVertexCirculator heavc(mesh, querryV);
    for( auto const& nhe : heavc )
    {
        std::cout << "  Half-Edge " << nhe << " (" << mesh->from_vertex(nhe) << " to " << mesh->to_vertex(nhe) << ")" << std::endl;
    }
}

void questionB_printFacesAroundVertex(const pmp::SurfaceMesh* const mesh,
                                      const pmp::Vertex&            querryV)
{
    std::cout << "Faces around vertex " << querryV << ":\n"
              << "-----------------------" << std::endl;

    pmp::SurfaceMesh::FaceAroundVertexCirculator favc(mesh, querryV);
    for( auto const& nf : favc )
    {
        std::cout << "  Face " << nf << " made of:\n    ";

        pmp::SurfaceMesh::VertexAroundFaceCirculator vafc = mesh->vertices(nf);
        for( auto const& nv : vafc )
        {
            std::cout << nv << " ";
        }
        std::cout << std::endl;
    }
}

void questionC_printVerticesAroundFace(const pmp::SurfaceMesh* const mesh,
                                       const pmp::Face&              querryF)
{
    std::cout << "Vertices around face " << querryF << ":\n"
              << "------------------------" << std::endl;

    pmp::SurfaceMesh::VertexAroundFaceCirculator vafc(mesh, querryF);
    for( auto nv : vafc )
    {
        std::cout << "  Vertex " << nv << std::endl;
    }
}

void questionC_printHalfEdgesAroundFace(const pmp::SurfaceMesh* const mesh,
                                        const pmp::Face&              querryF)
{
    std::cout << "Half-Edges around face " << querryF << ":\n"
              << "--------------------------" << std::endl;

    pmp::SurfaceMesh::HalfedgeAroundFaceCirculator heafc(mesh, querryF);
    for( auto nhe : heafc )
    {
        std::cout << "  Half-Edge " << nhe << " (" << mesh->from_vertex(nhe) << " to " << mesh->to_vertex(nhe) << ")" << std::endl;
    }
}

void questionC_printFacesAroundFace(const pmp::SurfaceMesh* const mesh,
                                    const pmp::Face&              querryF)
{
    std::cout << "Faces around face " << querryF << ":\n"
              << "---------------------" << std::endl;

    pmp::SurfaceMesh::HalfedgeAroundFaceCirculator heafc(mesh, querryF);
    for( auto nhe : heafc )
    {
        auto oppositeHe = mesh->opposite_halfedge(nhe);
        if( !mesh->is_boundary(oppositeHe) )
        {
            printFace(mesh, mesh->face(oppositeHe), "  ");
        }
    }
}