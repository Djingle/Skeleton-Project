#include <iostream>

#include "../include/cli_tools.h"
#include "../include/correction_tp1_ex2_tools.h"

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
    inputMesh.read(inputMeshPath);
    std::cout << "Successfully loaded mesh from \"" << inputMeshPath << "\"" << std::endl;
    const pmp::SurfaceMesh* const inputMeshPtr = &inputMesh;

    // Get first vertex and the first face of the mesh
    pmp::Vertex   v0  = *(inputMesh.vertices_begin());
    pmp::Face     f0  = *(inputMesh.faces_begin());
    pmp::Halfedge he0 = *(inputMesh.halfedges_begin());

    // ****************************************************************************************
    // A - Print connectivity from half-edge he0
    // ****************************************************************************************
    questionA_printVerticesOfHalfEdge(inputMeshPtr, he0);
    waitUserInput();

    questionA_printIncidentFaceOfHalfEdge(inputMeshPtr, he0);
    waitUserInput();

    questionA_printVerticesOfOppositeHalfEdge(inputMeshPtr, he0);
    waitUserInput();

    questionA_printVerticesOfNextHalfEdge(inputMeshPtr, he0);
    waitUserInput();

    questionA_printVerticesOfPreviousHalfEdge(inputMeshPtr, he0);
    waitUserInput();

    // ****************************************************************************************
    // B - Print connectivity from vertex v0
    // ****************************************************************************************
    questionB_printVerticesAroundVertex(inputMeshPtr, v0);
    waitUserInput();

    questionB_printHalfEdgesAroundVertex(inputMeshPtr, v0);
    waitUserInput();

    questionB_printFacesAroundVertex(inputMeshPtr, v0);
    waitUserInput();

    // ****************************************************************************************
    // C - Print connectivity from face f0
    // ****************************************************************************************
    questionC_printVerticesAroundFace(inputMeshPtr, f0);
    waitUserInput();

    questionC_printHalfEdgesAroundFace(inputMeshPtr, f0);
    waitUserInput();

    questionC_printFacesAroundFace(inputMeshPtr, f0);

    return 0;
}