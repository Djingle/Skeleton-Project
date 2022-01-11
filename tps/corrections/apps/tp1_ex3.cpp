#include <iostream>

#include "../include/cli_tools.h"
#include "../include/tp1_ex3_tools.h"

int main(int argc, char** argv)
{
    // Parsing command line *******************************************************************
    // Set required arguments
    std::vector< ArgPair > requiredArgs;

    requiredArgs.push_back( ArgPair("inputMeshPath",
                                    "Path of the mesh to be loaded") );
    requiredArgs.push_back( ArgPair("outputMeshPath",
                                    "Path of the mesh to be saved") );
    requiredArgs.push_back( ArgPair("affineTransf11",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf12",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf13",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf14",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf21",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf22",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf23",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf24",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf31",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf32",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf33",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf34",
                                    "Affine transformation coefficient") );    
    requiredArgs.push_back( ArgPair("affineTransf41",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf42",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf43",
                                    "Affine transformation coefficient") );
    requiredArgs.push_back( ArgPair("affineTransf44",
                                    "Affine transformation coefficient") );

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
    float       coeff11;
    float       coeff12;
    float       coeff13;
    float       coeff14;
    float       coeff21;
    float       coeff22;
    float       coeff23;
    float       coeff24;
    float       coeff31;
    float       coeff32;
    float       coeff33;
    float       coeff34;
    float       coeff41;
    float       coeff42;
    float       coeff43;
    float       coeff44;
    try
    {
        inputMeshPath  = argv[iArg++];
        outputMeshPath = argv[iArg++];
        coeff11        = std::stof(argv[iArg++]);
        coeff12        = std::stof(argv[iArg++]);
        coeff13        = std::stof(argv[iArg++]);
        coeff14        = std::stof(argv[iArg++]);
        coeff21        = std::stof(argv[iArg++]);
        coeff22        = std::stof(argv[iArg++]);
        coeff23        = std::stof(argv[iArg++]);
        coeff24        = std::stof(argv[iArg++]);
        coeff31        = std::stof(argv[iArg++]);
        coeff32        = std::stof(argv[iArg++]);
        coeff33        = std::stof(argv[iArg++]);
        coeff34        = std::stof(argv[iArg++]);
        coeff41        = std::stof(argv[iArg++]);
        coeff42        = std::stof(argv[iArg++]);
        coeff43        = std::stof(argv[iArg++]);
        coeff44        = std::stof(argv[iArg++]);
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

    // Constructs the PMP affine transformation from coeffiients
    pmp::Mat4<float> affineTrasformation(coeff11, coeff12, coeff13, coeff14,
                                         coeff21, coeff22, coeff23, coeff24,
                                         coeff31, coeff32, coeff33, coeff34,
                                         coeff41, coeff42, coeff43, coeff44);
    std::cout << "Affine transformation:\n"
              << "----------------------\n"
              << affineTrasformation << std::endl;

    transformMesh(inputMesh, affineTrasformation);

    // Write the output mesh
    inputMesh.write(outputMeshPath);
    std::cout << "Successfully saved mesh in \"" << outputMeshPath << "\"" << std::endl;

    return 0;
}