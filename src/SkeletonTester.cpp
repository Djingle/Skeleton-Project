///
/// \file SkeletonTester.cpp
/// \brief Source file of SkeletonTester
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 1.0.0
///

#include "SkeletonTester.h"

SkeletonTester::SkeletonTester(int quality_speed_tradeoff, 
                               int medially_centered_speed_tradeoff)                
{
    // Init skeletizator
    Skeletizator *temp_sk = new Skeletizator(quality_speed_tradeoff,
                                             medially_centered_speed_tradeoff);

    skeletizator_ = temp_sk;
}

void SkeletonTester::compute_radial_lengths()
{
    // Mean distance from a skeleton vertex to the corresponding vertices
    double current_distance;
    double mean_distance;
    double min_distance;
    double max_distance;

    // Number of links vertices to the current skeleton vertex
    int n_links;

    // For each vertex on the skeleton
    for(Skeleton_vertex v : CGAL::make_range(vertices(*skeletizator_->CGAL_skel_)))
    {
        mean_distance = 0.0;
        max_distance = std::numeric_limits<double>::min();
        min_distance = std::numeric_limits<double>::max();
        n_links = 0;

        // For each vertex corresponding to the skeleton vertex
        // Compute mean_distance
        // Get min_distance
        // Get max_distance
		for(vertex_descriptor vd : (*skeletizator_->CGAL_skel_)[v].vertices)
        {
            n_links++;
            current_distance = sqrt(CGAL::squared_distance((*skeletizator_->CGAL_skel_)[v].point, 
                                                            get(CGAL::vertex_point, *skeletizator_->mesh_, vd)));

            mean_distance += current_distance;
            max_distance = std::max(max_distance, current_distance);
            min_distance = std::min(min_distance, current_distance);
        }

        mean_distance = mean_distance/static_cast<double>(n_links);

        mean_rlenght_.push_back(mean_distance);
        max_rlenght_.push_back(max_distance);
        min_rlenght_.push_back(min_distance);
        n_links_.push_back(n_links);
    }
}

void SkeletonTester::output(const char* path)
{
    // New output file
    std::filesystem::path output_path = path;
    std::ofstream output_file(output_path.replace_extension("out"));

    // Line 1 : duration in seconds
    output_file << duration_ << "\n";

    // Line 2 : mesh vertex count and skeleton vertex count
    output_file << n_vertices_ << " " << n_skel_vertices_ << "\n";

    // Line 3 : mesh edge count and skeleton edge count
    output_file << n_edges_ << " " << n_skel_edges_ << "\n";

    // Line 4+ : for each skeleton vertex
    // number of links, min radial length, mean radial lenght, max radial lenght
    for(unsigned int i = 0; i < n_links_.size(); i++){
        output_file << n_links_[i] << " ";
        output_file << min_rlenght_[i] << " ";
        output_file << mean_rlenght_[i] << " ";
        output_file << max_rlenght_[i] << "\n";
    }

    // Close file
    output_file.close();
}

void SkeletonTester::start(const char* path)
{
    // Init skeletizator
    if(!skeletizator_->init(path))
        return;
        
    n_vertices_ = boost::num_vertices(*skeletizator_->mesh_);
    n_edges_ = boost::num_edges(*skeletizator_->mesh_);

    // Compute and time skeletonization operation
    std::time_t start_time, end_time;

    std::time(&start_time);
    skeletizator_->compute_skeleton();
    std::time(&end_time);

    duration_ = end_time - start_time;

    // Get informations from skeleton
    n_skel_vertices_ = boost::num_vertices(*skeletizator_->CGAL_skel_);
    n_skel_edges_ = boost::num_edges(*skeletizator_->CGAL_skel_);
    compute_radial_lengths();

    // Output informations
    output(path);
}

