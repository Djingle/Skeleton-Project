#include <iostream>
#include <string>

#include "pmp/SurfaceMesh.h"

void waitUserInput()
{
    // Wait for user input before going on              
    std::cout << "Program paused, press any key to continue." << std::endl;
    std::cin.get();    
}

int main(int argc, char** argv)
{
    // Get filename from the command line arguments
    std::string inputFileName;
    if( argc > 1 )
    {
        inputFileName = argv[1];
    }
    else
    {
        std::cerr << "Argument missing: must provide the path of the mesh to be loaded. \nAbort process" << std::endl;
        return 1;
    }

    // Load the mesh
    pmp::SurfaceMesh inputMesh;
    if( !inputMesh.read(inputFileName) )
    {
        std::cerr << "An error occured while loading the mesh \"" << inputFileName << "\".\n Abort process." << std::endl;
        return 2;
    }

    // Print general information about the loaded mesh
    std::cout << "Mesh \"" << inputFileName << "\" is made of:\n"
              << "\t" << inputMesh.n_vertices()  << " vertices\n"
              << "\t" << inputMesh.n_edges()     << " edges\n"
              << "\t" << inputMesh.n_halfedges() << " half edges\n"
              << "\t" << inputMesh.n_faces()     << " faces\n" << std::endl;

    // Wait for user input before going on              
    waitUserInput();

    // // Print the vertices - First option
    // size_t iVertex = 0;
    // for(auto currVertex : inputMesh.vertices())
    // {
    //     std::cout << "Vertex " << iVertex << ": " << inputMesh.position(currVertex) << "\n";
    //     iVertex++;
    // }
    // std::cout << std::endl;

    // // Print the vertices - Second option : classical loop (without auto)
    // iVertex = 0;
    // for( pmp::SurfaceMesh::VertexIterator vIt = inputMesh.vertices_begin() ; vIt != inputMesh.vertices_end() ; ++vIt )
    // {
    //     std::cout << "Vertex " << iVertex << ": " << inputMesh.position(*vIt) << "\n";
    //     iVertex++;
    // }
    // std::cout << std::endl;

    // // Print the vertices - Third option : while loop and only print the first few vertices
    // iVertex = 0;
    // size_t nMaxVerticesToPrint = 20;
    // pmp::SurfaceMesh::VertexIterator vIt = inputMesh.vertices_begin();
    // while( iVertex < nMaxVerticesToPrint && vIt != inputMesh.vertices_end() )
    // {
    //     std::cout << "Vertex " << iVertex << ": " << inputMesh.position(*vIt) << "\n";
    //     ++vIt;
    //     iVertex++;
    // }
    // std::cout << std::endl;

    // // Wait for user input before going on              
    // system("pause");

    // // Print the edges via half edges
    // size_t iEdge = 0;
    // for(auto currEdge : inputMesh.edges())
    // {
    //     // Get the first half edge corresponding to the current edge
    //     pmp::Halfedge hEdge = inputMesh.halfedge(currEdge, 0);

    //     // Print the vertices of the half edge
    //     std::cout << "Edge " << iEdge << ": (" << inputMesh.from_vertex(hEdge) << ", " << inputMesh.to_vertex(hEdge) << ")\n";
    //     iEdge++;
    // }
    // std::cout << std::endl;

    // system("pause");

    // // Print the faces
    // size_t iFace = 0;
    // for(auto currFace : inputMesh.faces())
    // {
    //     size_t nVerticesInCurrFace = inputMesh.valence(currFace);
    //     std::cout << "The face " << iFace << " has " << nVerticesInCurrFace << " vertices: ";

    //     pmp::SurfaceMesh::VertexAroundFaceCirculator vafc = inputMesh.vertices(currFace);
    //     for( size_t i = 0 ; i < nVerticesInCurrFace ; i++ )
    //     {
    //         std::cout << *vafc << " ";
    //         ++vafc;
    //     }
    //     std::cout << "\n";

    //     iFace++;
    // }
    // std::cout << std::endl;

    return 0;
}