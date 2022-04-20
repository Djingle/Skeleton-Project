///
/// \file main.cpp
/// \brief Main application
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 0.2.0
///

#include <iostream>
#include <CGAL/internal/Surface_mesh_skeletonization/Curve_skeleton.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Surface_mesh/Surface_mesh.h>
#include <CGAL/Surface_mesh/IO.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>

#include <fstream>
#include "./cli_tools.h"
#include "./SkeletonMeshViewer.h"

typedef CGAL::Simple_cartesian<double> K;
typedef CGAL::Surface_mesh<K::Point_3> Mesh;

int main(int argc, char **argv)
{
    // Parsing command line *******************************************************************
    // Set required arguments
    std::vector<ArgPair> requiredArgs;

    requiredArgs.push_back(ArgPair("inputMeshPath",
                                   "Path of the mesh to be loaded"));

    // Check command line validity
    if ((size_t)argc != requiredArgs.size() + 1)
    {
        std::cerr << "Error: command line arguments do not fit with usage" << std::endl;
        printUsage(argc, argv, requiredArgs);
        return -1;
    }

    // Get arguments from command line
    int iArg = 1;
    std::string inputMeshPath;
    try
    {
        inputMeshPath = argv[iArg++];
    }
    catch (const std::exception &e)
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

    // Test
    Mesh testMesh;
    read_mesh(testMesh, inputMeshPath);

    // Instanciate a mesh viewer and attach the input mesh
    std::string winTitle = "Skeleton Viewer ";
    int winWidth = 800;
    int winHeight = 600;
    SkeletonMeshViewer meshViewer{winTitle.c_str(),
                                  winWidth, winHeight,
                                  inputMesh};

    // Start main window loop
    meshViewer.run();

    return 0;
}
