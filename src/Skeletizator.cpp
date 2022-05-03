///
/// \file Skeletizator.cpp
/// \brief Source file of Skeletizator
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 1.0.0
///

#include "Skeletizator.h"

Skeletizator::Skeletizator(int quality_speed_tradeoff, 
                           int medially_centered_speed_tradeoff) : quality_speed_tradeoff_(quality_speed_tradeoff),
                                                                   medially_centered_speed_tradeoff_(medially_centered_speed_tradeoff),
                                                                   skeletizator_(std::ifstream(""))
                                                                                     
{
    min_radial_length_ = std::numeric_limits<double>::max();
    max_radial_length_ = std::numeric_limits<double>::min();
}

void Skeletizator::init(std::string path)
{    
    std::ifstream input(path);
    input >> mesh_;

    if(!CGAL::is_triangle_mesh(mesh_))
    {
        std::cout << "Input mesh is not triangulated." << std::endl;
        return EXIT_FAILURE;
    }

    // Init CGAL skeleton class
    skeletizator_ = Skeletonization(mesh_);

    skeletizator_.set_is_medially_centered(true);
    skeletizator_.set_quality_speed_tradeoff(quality_speed_tradeoff_ * skeletizator_.quality_speed_tradeoff());
    skeletizator_.set_medially_centered_speed_tradeoff(medially_centered_speed_tradeoff_ * skeletizator_.medially_centered_speed_tradeoff()); 
}

void Skeletizator::compute_skeleton()
{
    skeletizator_.contract_until_convergence();
    skeletizator_.convert_to_skeleton(CGAL_skel_);
}

void Skeletizator::convert_to_pmp_mesh()
{
    // Remove previous skeleton
    PMP_skel_.clear();

    // Current skeleton vertex
    pmp::Vertex current_skeleton_vertex;

    // Mean distance from a skeleton vertex to the corresponding vertices
    double mean_distance;

    // Number of corresponding vertices to the current skeleton vertex
    int n_corresp;
    
    auto radial_length = PMP_skel_.vertex_property<double>("radial_length");

    // For each vertex on the skeleton
    for(Skeleton_vertex v : CGAL::make_range(vertices(CGAL_skel_)))
    {
        mean_distance = 0.0;
        n_corresp = 0;

        // For each vertex corresponding to the skeleton vertex
        // Compute mean_distance
		for(vertex_descriptor vd : CGAL_skel_[v].vertices)
        {
            n_corresp++;
            mean_distance += sqrt(CGAL::squared_distance(CGAL_skel_[v].point, 
                                                         get(CGAL::vertex_point, mesh_, vd)));
        }

        mean_distance = mean_distance/static_cast<double>(n_corresp);

        // Add current skeleton vertex and mean distance to PMP mesh
        current_skeleton_vertex = PMP_skel_.add_vertex(pmp::Point(CGAL_skel_[v].point[0],
                                                                  CGAL_skel_[v].point[1],
                                                                  CGAL_skel_[v].point[2]));
        
        radial_length[current_skeleton_vertex] = mean_distance;

        // Update max and min mean radial lenght
        if (mean_distance > max_radial_length_) {
            max_radial_length_ = mean_distance;
        }

        if (mean_distance < min_radial_length_) {
            min_radial_length_ = mean_distance;
        }
    }
}
