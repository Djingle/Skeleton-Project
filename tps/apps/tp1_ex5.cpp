#include <iostream>

#include <pmp/visualization/MeshViewer.h>

#include "../include/cli_tools.h"
#include "../include/tp1_ex5_tools.h"

int main(int argc, char** argv)
{
    // Parsing command line *******************************************************************
    // Set required arguments
    std::vector< ArgPair > requiredArgs;

    requiredArgs.push_back( ArgPair("inputMeshPath1",
                                    "Path of the first mesh to be loaded") );
    requiredArgs.push_back( ArgPair("inputMeshPath2",
                                    "Path of the second mesh to be loaded") );

    // Check command line validity
    if( (size_t)argc != requiredArgs.size()+1 )
    {
        std::cerr << "Error: command line arguments do not fit with usage" << std::endl;
        printUsage(argc, argv, requiredArgs);
        return -1;
    }

    // Get arguments from command line
    int         iArg  = 1;
    std::string inputMeshPath1;
    std::string inputMeshPath2;
    try
    {
        inputMeshPath1 = argv[iArg++];
        inputMeshPath2 = argv[iArg++];
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error while parsing arguments:" << std::endl;
        std::cerr << e.what() << "\n";
        std::cerr << "Abort process." << std::endl;
        return 1;
    }    
    // ****************************************************************************************

    // Load the input meshes
    std::vector<pmp::SurfaceMeshGL*> meshes;
    std::vector<std::string>         meshesName;

    pmp::SurfaceMeshGL inputMesh1;
    inputMesh1.read(inputMeshPath1);
    std::cout << "Successfully loaded mesh from \"" << inputMeshPath1 << "\"" << std::endl;
    meshes.push_back(&inputMesh1);
    meshesName.push_back(inputMeshPath1);

    pmp::SurfaceMeshGL inputMesh2;
    inputMesh2.read(inputMeshPath2);
    std::cout << "Successfully loaded mesh from \"" << inputMeshPath2 << "\"" << std::endl;
    meshes.push_back(&inputMesh2);
    meshesName.push_back(inputMeshPath2);

// Instanciate a mesh viewer and attach the input mesh
    std::string winTitle = "TP 1 - Ex.4 - Interface graphique et visualisation";
    int winWidth         = 800;
    int winHeight        = 600;
    TP1_Ex5_MeshViewer meshViewer(winTitle.c_str(),
                                  winWidth, winHeight,
                                  meshes, meshesName);

    // Start main window loop
    meshViewer.run();

    return 0;
}