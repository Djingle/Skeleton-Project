#include <iostream>

#include "../include/cli_tools.h"

#include "pmp/SurfaceMesh.h"

void waitUserInput()
{
    // Wait for user input before going on              
    std::cout << "Program paused, press any key to continue." << std::endl;
    std::cin.get();    
}

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
                                   size_t                     nVerticesToPrint=0)
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
                                   size_t                     nVerticesToPrint=0)
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
                                   size_t                     nVerticesToPrint=0)
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

void questionC_printMeshEdges(const pmp::SurfaceMesh&   mesh,
                              size_t                    nEdgesToPrint=0)
{
    if( nEdgesToPrint == 0 || nEdgesToPrint >= mesh.n_edges() )
    {
        nEdgesToPrint = mesh.n_edges();
    }

    std::cout << "Mesh edges:\n"
              << "-----------" << std::endl;

    size_t iEdge = 0;
    for(auto currEdge : mesh.edges())
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

void questionD_printMeshFaces(const pmp::SurfaceMesh&   mesh,
                              size_t                    nFacesToPrint=0)
{
    if( nFacesToPrint == 0 || nFacesToPrint >= mesh.n_faces() )
    {
        nFacesToPrint = mesh.n_faces();
    }

    std::cout << "Mesh faces:\n"
              << "-----------" << std::endl;

    size_t iFace = 0;
    for(auto currFace : mesh.faces())
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

int main(int argc, char** argv)
{
    // Parsing command line *******************************************************************
    // Set required arguments
    std::vector< ArgPair > requiredArgs;

    requiredArgs.push_back( ArgPair("inputMeshPath",
                                    "Path of the mesh to be loaded") );

    // Check command line validity
    if( (size_t)argc != requiredArgs.size()+1 )
    {
        std::cerr << "Error: command line arguments do not fit with usage" << std::endl;
        printUsage(argc, argv, requiredArgs);
        return -1;
    }

    // Get arguments from command line
    int         iArg  = 1;
    std::string inputMeshPath;
    try
    {
        inputMeshPath  = argv[iArg++];
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error while parsing arguments:" << std::endl;
        std::cerr << e.what() << "\n";
        std::cerr << "Abort process." << std::endl;
        return 1;
    }    
    // ****************************************************************************************

    // Load the input mesh
    pmp::SurfaceMesh inputMesh;
    if( !inputMesh.read(inputMeshPath) )
    {
        std::cerr << "An error occured while loading the mesh from \"" << inputMeshPath << "\".\n Abort process." << std::endl;
        return 2;
    }
    std::cout << "Successfully loaded mesh from \"" << inputMeshPath << "\"" << std::endl;

    // ****************************************************************************************
    // A - Print general information about the loaded mesh
    // ****************************************************************************************
    questionA_printGeneralInformationAboutMesh(inputMesh, inputMeshPath);

    // Wait for user input before continuing
    waitUserInput();

    // ****************************************************************************************
    // B - Print vertices
    // ****************************************************************************************
    size_t nMaxVerticesToPrint = 20;
    questionB_printMeshVerticesV1(inputMesh, nMaxVerticesToPrint);
    // questionB_printMeshVerticesV2(inputMesh, nMaxVerticesToPrint);
    // questionB_printMeshVerticesV3(inputMesh, nMaxVerticesToPrint);
    
    // Wait for user input before continuing
    waitUserInput();

    // ****************************************************************************************
    // C - Print the edges via half edges
    // ****************************************************************************************
    size_t nMaxEdgesToPrint = 20;
    questionC_printMeshEdges(inputMesh, nMaxEdgesToPrint);

    // Wait for user input before continuing
    waitUserInput();

    // ****************************************************************************************
    // D - Print the faces
    // ****************************************************************************************
    size_t nMaxFacesToPrint = 20;
    questionD_printMeshFaces(inputMesh, nMaxFacesToPrint);

    return 0;
}