#include <iostream>

#include <pmp/visualization/MeshViewer.h>

#include "../include/cli_tools.h"
#include "../include/tp1_ex4_tools.h"

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
    pmp::SurfaceMeshGL inputMesh;
    inputMesh.read(inputMeshPath);
    std::cout << "Successfully loaded mesh from \"" << inputMeshPath << "\"" << std::endl;
    const pmp::SurfaceMeshGL* const inputMeshPtr = &inputMesh;

    // Instanciate a mesh viewer and attach the input mesh
    std::string winTitle = "TP 1 - Ex.3 - Interface graphique et visualisation";
    int winWidth         = 800;
    int winHeight        = 600;
    TP1_Ex4_MeshViewer meshViewer(winTitle.c_str(),
                                  winWidth, winHeight,
                                  inputMesh);

    // Start main window loop
    meshViewer.run();

    return 0;
}