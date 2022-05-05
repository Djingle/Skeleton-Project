///
/// \file SkeletonTester.h
/// \brief Header file of SkeletonTester
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 1.0.0
///

#ifndef SKELETON_TESTER_H
#define SKELETON_TESTER_H

#include <ctime>
#include <vector>
#include <filesystem>
#include <iostream>

#include "Skeletizator.h"

///
/// \brief Skeleton testerer
///
class SkeletonTester
{
public:
    ///
    /// \fn SkeletonTester SkeletonTester::SkeletonTester(int quality_speed_tradeoff, int medially_centered_speed_tradeoff)
    /// \brief Perform multiple tests on the source mesh and its skeleton
    ///
    /// \param quality_speed_tradeoff Value of quality parameter
    /// \param medially_centered_speed_tradeoff Value of medial axis parameter
    ///
    SkeletonTester(int quality_speed_tradeoff, 
                   int medially_centered_speed_tradeoff);

    ///
    /// \fn void start(const char* path)
    /// \brief Perform multiple tests on the source mesh and its skeleton
    ///
    /// \param path Path to .off file
    ///
    void start(const char* path);

private:
    ///
    /// \fn compute_radial_lengths()
    /// \brief Compute all radial lenghts informations
    ///
    void compute_radial_lengths();

    ///
    /// \fn output(const char* path)
    /// \brief Output informations to text file
    ///
    void output(const char* path);

    // Skeletizator
    Skeletizator* skeletizator_;

    // Mesh informations
    int n_vertices_;                    // Input mesh number of vertices
    int n_edges_;                       // Input mesh number of edges

    // Skeleton informations
    int n_skel_vertices_;               // Output skeleton number of vertices
    int n_skel_edges_;                  // Output skeleton number of edges
    std::vector<double> mean_rlenght_;  // Output skeleton mean radial lenght per vertex
    std::vector<double> min_rlenght_;   // Output skeleton min radial lenght per vertex
    std::vector<double> max_rlenght_;   // Output skeleton max radial lenght per vertex
    std::vector<int> n_links_;          // Output skeleton number of links per vertex

    // Test results
    std::time_t duration_;
};

#endif