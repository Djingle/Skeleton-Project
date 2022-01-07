#include "../include/tp1_ex1_tools.h"

void questionA_printGeneralInformationAboutMesh(const pmp::SurfaceMesh&   mesh,
                                                const std::string&        meshName)
{
    std::cout << "Mesh information:\n"
              << "-----------------" << std::endl;

    std::cout << "  Mesh \"" << meshName << "\" is made of:\n"
              << "  " << mesh.n_vertices()  << " vertices\n"
              << "  " << mesh.n_edges()     << " edges\n"
              << "  " << mesh.n_halfedges() << " half edges\n"
              << "  " << mesh.n_faces()     << " faces\n" << std::endl;
}

void questionB_printMeshVerticesV1(const pmp::SurfaceMesh&    mesh,
                                   size_t                     nVerticesToPrint)
{
    if( nVerticesToPrint == 0 || nVerticesToPrint >= mesh.n_vertices() )
    {
        nVerticesToPrint = mesh.n_vertices();
    }

    std::cout << "Mesh vertices (auto for loop):\n"
              << "------------------------------" << std::endl;
    size_t iVertex = 0;
    for(auto const& currVertex : mesh.vertices())
    {
        std::cout << "  Vertex " << iVertex << ": " << mesh.position(currVertex) << "\n";
        iVertex++;

        if( iVertex >= nVerticesToPrint )
        {
            break;
        }
    }
    std::cout << std::endl;
}

void questionB_printMeshVerticesV2(const pmp::SurfaceMesh&    mesh,
                                   size_t                     nVerticesToPrint)
{
    if( nVerticesToPrint == 0 || nVerticesToPrint >= mesh.n_vertices() )
    {
        nVerticesToPrint = mesh.n_vertices();
    }

    std::cout << "Mesh vertices (iterator for loop):\n"
              << "----------------------------------" << std::endl;

    size_t iVertex = 0;
    for( pmp::SurfaceMesh::VertexIterator vIt = mesh.vertices_begin() ; vIt != mesh.vertices_end() && iVertex < nVerticesToPrint ; ++vIt )
    {
        std::cout << "  Vertex " << iVertex << ": " << mesh.position(*vIt) << "\n";
        iVertex++;
    }
    std::cout << std::endl;
}

void questionB_printMeshVerticesV3(const pmp::SurfaceMesh&    mesh,
                                   size_t                     nVerticesToPrint)
{
    if( nVerticesToPrint == 0 || nVerticesToPrint >= mesh.n_vertices() )
    {
        nVerticesToPrint = mesh.n_vertices();
    }

    std::cout << "Mesh vertices (while loop):\n"
              << "---------------------------" << std::endl;

    size_t iVertex = 0;
    pmp::SurfaceMesh::VertexIterator vIt = mesh.vertices_begin();
    while( iVertex < nVerticesToPrint && vIt != mesh.vertices_end() )
    {
        std::cout << "  Vertex " << iVertex << ": " << mesh.position(*vIt) << "\n";
        ++vIt;
        iVertex++;
    }
    std::cout << std::endl;
}

void questionC_printMeshHalfEdges(const pmp::SurfaceMesh&   mesh,
                                  size_t                    nHalfEdgesToPrint)
{
    if( nHalfEdgesToPrint == 0 || nHalfEdgesToPrint >= mesh.n_halfedges() )
    {
        nHalfEdgesToPrint = mesh.n_halfedges();
    }

    std::cout << "Mesh half-edges:\n"
              << "-----------" << std::endl;

    size_t iHEdge = 0;
    for(auto const& currHEdge : mesh.halfedges())
    {
        // Print the vertices of the half edge
        std::cout << "  Half-Edge " << iHEdge << ": (" << mesh.from_vertex(currHEdge) << ", " << mesh.to_vertex(currHEdge) << ")\n";
        iHEdge++;

        if( iHEdge >= nHalfEdgesToPrint )
        {
            break;
        }
    }
    std::cout << std::endl;
}

void questionD_printMeshEdges(const pmp::SurfaceMesh&   mesh,
                              size_t                    nEdgesToPrint)
{
    if( nEdgesToPrint == 0 || nEdgesToPrint >= mesh.n_edges() )
    {
        nEdgesToPrint = mesh.n_edges();
    }

    std::cout << "Mesh edges:\n"
              << "-----------" << std::endl;

    size_t iEdge = 0;
    for(auto const& currEdge : mesh.edges())
    {
        // Get the first half edge corresponding to the current edge
        pmp::Halfedge hEdge = mesh.halfedge(currEdge, 0);

        // Print the vertices of the half edge
        std::cout << "  Edge " << iEdge << ": (" << mesh.from_vertex(hEdge) << ", " << mesh.to_vertex(hEdge) << ")\n";
        iEdge++;

        if( iEdge >= nEdgesToPrint )
        {
            break;
        }
    }
    std::cout << std::endl;
}

void questionE_printMeshFaces(const pmp::SurfaceMesh&   mesh,
                              size_t                    nFacesToPrint)
{
    if( nFacesToPrint == 0 || nFacesToPrint >= mesh.n_faces() )
    {
        nFacesToPrint = mesh.n_faces();
    }

    std::cout << "Mesh faces:\n"
              << "-----------" << std::endl;

    size_t iFace = 0;
    for(auto const& currFace : mesh.faces())
    {
        size_t nVerticesInCurrFace = mesh.valence(currFace);
        std::cout << "  Face " << iFace << " has " << nVerticesInCurrFace << " vertices: ";

        pmp::SurfaceMesh::VertexAroundFaceCirculator vafc = mesh.vertices(currFace);
        for( size_t i = 0 ; i < nVerticesInCurrFace ; i++ )
        {
            std::cout << *vafc << " ";
            ++vafc;
        }
        std::cout << "\n";

        iFace++;

        if( iFace >= nFacesToPrint )
        {
            break;
        }
    }
    std::cout << std::endl;
}