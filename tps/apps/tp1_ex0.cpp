#include <iostream>

#include "../include/cli_tools.h"

#include "pmp/SurfaceMesh.h"

int main(int argc, char** argv)
{
    // Parsing command line *******************************************************************
    // Set required arguments
    std::vector< ArgPair > requiredArgs;

    requiredArgs.push_back( ArgPair("inputMeshPath",
                                    "Path of the mesh to be loaded") );
    requiredArgs.push_back( ArgPair("outputMeshPath",
                                    "Path of the mesh to be saved") );

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
    std::string outputMeshPath;
    try
    {
        inputMeshPath  = argv[iArg++];
        outputMeshPath = argv[iArg++];
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

    // Write the output mesh
    if( !inputMesh.write(outputMeshPath) )
    {
        std::cerr << "An error occured while saving the mesh in \"" << outputMeshPath << "\".\n Abort process." << std::endl;
        return 3;       
    }
    std::cout << "Successfully saved mesh in \"" << outputMeshPath << "\"" << std::endl;

    return 0;
}