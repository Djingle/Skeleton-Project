#include "../include/correction_tp2_ex4_tools.h"

#include <pmp/algorithms/DifferentialGeometry.h>

void printBoundingBoxCoords(pmp::SurfaceMesh& mesh)
{
    std::cout << "BBox coordinates:\n"
              << "-----------------\n"
              << "  " << mesh.bounds().min() << "\n"
              << "  " << mesh.bounds().max() << std::endl;
}

void printBoundingBoxSize(pmp::SurfaceMesh& mesh)
{
    std::cout << "BBox lengths:\n"
              << "-------------\n"
              << "  " << mesh.bounds().max() - mesh.bounds().min() << std::endl;
}

void printBoundingBoxDiag(pmp::SurfaceMesh& mesh)
{
    std::cout << "BBox diagonal:\n"
              << "--------------\n"
              << "  " << mesh.bounds().size() << std::endl;
}

void printMeshTotalArea(pmp::SurfaceMesh& mesh)
{
    try
    {
        std::cout << "Total area:\n"
                  << "-----------\n"
                  << "  " << pmp::surface_area(mesh) << "m^2\n" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "Could not compute total mesh area\n" << std::endl;
    }
}

void printMeshVerticesCentroid(pmp::SurfaceMesh& mesh)
{
    std::cout << "Vertices centroid:\n"
              << "------------------\n"
              << "  " << pmp::centroid(mesh) << "m^2\n" << std::endl;
}

void printMeshVolume(pmp::SurfaceMesh& mesh)
{
    std::cout << "Mesh volume:\n"
              << "------------\n"
              << "  " << pmp::volume(mesh) << "m^2\n" << std::endl;
}

void printEulerNumberAndGenus(pmp::SurfaceMesh& mesh)
{
    int eulerN = mesh.n_vertices() - mesh.n_edges() + mesh.n_faces();
    int genre  = 1 - (eulerN / 2);

    std::cout << "Euler characteristic:\n"
              << "---------------------\n"
              << "  Euler: " << eulerN
              << "  Genre: " << genre << std::endl;
}