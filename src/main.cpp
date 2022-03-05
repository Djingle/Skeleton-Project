#include <iostream>

#include "CustomSurfaceMeshGL.h"

int main(int argc, char** argv)
{
    if( argc < 2 )
    {
        std::cout << "Argument error (missing input mesh argument).\n"
                  << "Usage :\n"
                  << "-------\n"
                  << argv[0] << " input_mesh_off_format" << std::endl;
        
        return 1;
    }

    CustomSurfaceMeshGL inputMesh;
    // Lecture du fichier OFF
    // inputMesh.read(........)
    
    // Add random vertex color

    // Either visualize (pmp visualization module) or save the colored mesh

    return 0;
}
