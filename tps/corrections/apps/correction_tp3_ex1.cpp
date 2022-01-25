#include <iostream>

#include "../include/cli_tools.h"
#include "../include/correction_tp3_ex1_tools.h"

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
        inputMeshPath = argv[iArg++];
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
    pmp::SurfaceMeshGL inputMesh;
    std::cout << "Trying to read " << inputMeshPath << std::endl;
    inputMesh.read(inputMeshPath);
    std::cout << "Successfully loaded mesh from \"" << inputMeshPath << "\"" << std::endl;

    // Instanciate a mesh viewer and attach the input mesh
    std::string winTitle = "TP 3 - Ex.1 - Surface smoothing";
    int winWidth         = 800;
    int winHeight        = 600;
    TP3_Ex1_MeshViewer meshViewer(winTitle.c_str(),
                                  winWidth, winHeight,
                                  inputMesh);

    // Start main window loop
    meshViewer.run();

    return 0;
}