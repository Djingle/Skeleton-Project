///
/// \file Skeletizator.h
/// \brief Header file of Skeletizator
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 1.0.0
///



#ifndef SKELETIZATOR_H
#define SKELETIZATOR_H

#include <imgui.h>
#include <iostream>

#include "imfilebrowser.h"

#include <pmp/visualization/MeshViewer.h>

#include <CGAL/internal/Surface_mesh_skeletonization/Curve_skeleton.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Surface_mesh/Surface_mesh.h>
#include <CGAL/Surface_mesh/IO.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Mean_curvature_flow_skeletonization.h>
#include <CGAL/Polygon_mesh_processing/triangulate_faces.h>

typedef CGAL::Simple_cartesian<double>                        Kernel;
typedef Kernel::Point_3                                       Point;
typedef CGAL::Polyhedron_3<Kernel>                            Polyhedron;
typedef CGAL::Surface_mesh<Kernel::Point_3>                   Mesh;

typedef boost::graph_traits<Polyhedron>::vertex_descriptor    vertex_descriptor;

typedef CGAL::Mean_curvature_flow_skeletonization<Polyhedron> Skeletonization;
typedef Skeletonization::Skeleton                             Skeleton;

typedef Skeleton::vertex_descriptor                           Skeleton_vertex;
typedef Skeleton::edge_descriptor                             Skeleton_edge;

///
/// \brief Skeletizator
///
class Skeletizator
{
public:
    ///
    /// \fn Skeletizator Skeletizator::Skeletizator(int quality_speed_tradeoff, int medially_centered_speed_tradeoff)
    /// \brief Compute a skeleton from a .off file.
    ///
    /// \param quality_speed_tradeoff Speed paramater of Skeletizator
    /// \param medially_centered_speed_tradeoff Medial axis paramater of Skeletizator
    ///
    Skeletizator(int quality_speed_tradeoff, int medially_centered_speed_tradeoff);

    ///
    /// \fn bool init_skeletizator(std::string path)
    /// \brief Init skeletizator with mesh from file
    ///
    /// \param path path to .off file to load
    ///
    /// \return true if loading was succesful, false if not
    bool init(std::string path);

    ///
    /// \fn void compute_skeleton()
    /// \brief Compute a CGAL skeleton
    ///
    void compute_skeleton();

    ///
    /// \fn convert_to_pmp_mesh()
    /// \brief Convert a CGAL skeleton to a PMP mesh
    ///
    void convert_to_pmp_mesh();

    // Customizable skeletizator parameters
    int quality_speed_tradeoff_;
    int medially_centered_speed_tradeoff_;

    // Output skeletons
    Skeleton* CGAL_skel_;
    pmp::SurfaceMeshGL* PMP_skel_;

    // Skeleton attributs
    double max_radial_length_;
    double min_radial_length_;

private:
    // Input mesh
    Polyhedron* mesh_;

    // Skeletizor
    Skeletonization* skeletizator_;
};

#endif