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

#include <CGAL/Polyhedron_3.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Mean_curvature_flow_skeletonization.h>

#include <fstream>

typedef CGAL::Simple_cartesian<double>                        Kernel;
typedef Kernel::Point_3                                       Point;
typedef CGAL::Polyhedron_3<Kernel>                            Polyhedron;
typedef CGAL::Surface_mesh<Kernel::Point_3>                   Mesh;

typedef boost::graph_traits<Polyhedron>::vertex_descriptor    vertex_descriptor;

typedef CGAL::Mean_curvature_flow_skeletonization<Polyhedron> Skeletonization;
typedef Skeletonization::Skeleton                             Skeleton;

typedef Skeleton::vertex_descriptor                           Skeleton_vertex;
typedef Skeleton::edge_descriptor                             Skeleton_edge;

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
    pmp::SurfaceMeshGL inputMesh, skel;
        
        // Test
      std::ifstream input((argc>1)?argv[1]:inputMeshPath);
      Polyhedron tmesh;
      input >> tmesh;

      if (!CGAL::is_triangle_mesh(tmesh))
      {
        std::cout << "Input geometry is not triangulated." << std::endl;
        return EXIT_FAILURE;
      }

      Skeleton skeleton;
      Skeletonization mcs(tmesh);

    mcs.set_quality_speed_tradeoff(100*mcs.quality_speed_tradeoff());
    mcs.set_medially_centered_speed_tradeoff(100*mcs.medially_centered_speed_tradeoff());
    mcs.set_is_medially_centered(true);
    // 1. Contract the mesh by mean curvature flow.
    mcs.contract_geometry();

    // 2. Collapse short edges and split bad triangles.
    mcs.collapse_edges();
    mcs.split_faces();

    // 3. Fix degenerate vertices.
    mcs.detect_degeneracies();

    // Perform the above three steps in one iteration.
    mcs.contract();

    // Iteratively apply step 1 to 3 until convergence.
    mcs.contract_until_convergence();

    // Convert the contracted mesh into a curve skeleton and
    // get the correspondent surface points
    mcs.convert_to_skeleton(skeleton);

    std::cout << "Number of vertices of the skeleton: " << boost::num_vertices(skeleton) << "\n";
    std::cout << "Number of edges of the skeleton: " << boost::num_edges(skeleton) << "\n";

    // Output all the edges of the skeleton.
    std::ofstream output("skel-poly.polylines.txt");
    for(Skeleton_edge e : CGAL::make_range(edges(skeleton)))
    {
    const Point& s = skeleton[source(e, skeleton)].point;
    const Point& t = skeleton[target(e, skeleton)].point;
    output << "2 "<< s << " " << t << "\n";
    }
    output.close();

    // Output skeleton points and the corresponding surface points
    output.open("correspondance-poly.polylines.txt");
    //pmp::Vertex n_v;
    float m_distance;
    float n_liens; // nombre de correspondances
    pmp::Vertex n_v;
    for(Skeleton_vertex v : CGAL::make_range(vertices(skeleton))) {
        n_liens = 0.0;
        for(vertex_descriptor vd : skeleton[v].vertices) {
            n_liens++;
            output << skeleton[v].point << get(CGAL::vertex_point, tmesh, vd)  << "\n";
            m_distance += CGAL::squared_distance(skeleton[v].point, get(CGAL::vertex_point, tmesh, vd));
        }
        m_distance /= n_liens;
        n_v = skel.add_vertex(pmp::Point(skeleton[v].point[0],skeleton[v].point[1],skeleton[v].point[2]));
        auto dist = skel.vertex_property<float>("distance");
        dist[n_v] = m_distance;
        output << "\n\n" << m_distance << "\n" << dist[n_v] << "\n\n";
    }

    auto col = skel.vertex_property<pmp::Color>("v:color");
    for (auto v : skel.vertices()) {
        pmp::Color coul(0.0, 0.0, 0.0);
        std::cout << coul << std::endl;
        col[v] = coul;
    }


    // Load the input mesh
    

    std::cout << "Trying to read " << inputMeshPath << std::endl;
    inputMesh.read(inputMeshPath);
    std::cout << "Successfully loaded mesh from \"" << inputMeshPath << "\"" << std::endl;

    // Instanciate a mesh viewer and attach the input mesh
    std::string winTitle = "Skeleton Viewer ";
    int winWidth = 800;
    int winHeight = 600;
    SkeletonMeshViewer meshViewer{winTitle.c_str(),
                                  winWidth, winHeight,
                                  inputMesh, skel};

    // Start main window loop
    meshViewer.run();
    return 0;
}
