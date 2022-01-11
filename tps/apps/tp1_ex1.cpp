#include <iostream>

#include "../include/cli_tools.h"
#include "../include/tp1_ex1_tools.h"

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

    // Additional hard coded parameters
    size_t nMaxVerticesToPrint = 20;
    size_t nMaxEdgesToPrint    = 20;
    size_t nMaxFacesToPrint    = 20;

    // Load the input mesh
    pmp::SurfaceMesh inputMesh;
    inputMesh.read(inputMeshPath);
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
    questionB_printMeshVertices(inputMesh, nMaxVerticesToPrint);
    
    // Wait for user input before continuing
    waitUserInput();

    // ****************************************************************************************
    // C - Print the half edges
    // ****************************************************************************************
    questionC_printMeshHalfEdges(inputMesh, nMaxEdgesToPrint);
    
    // Wait for user input before continuing
    waitUserInput();
    
    // ****************************************************************************************
    // D - Print the edges via half edges
    // ****************************************************************************************
    questionD_printMeshEdges(inputMesh, nMaxEdgesToPrint);

    // Wait for user input before continuing
    waitUserInput();

    // ****************************************************************************************
    // E - Print the faces
    // ****************************************************************************************
    questionE_printMeshFaces(inputMesh, nMaxFacesToPrint);

    return 0;
}