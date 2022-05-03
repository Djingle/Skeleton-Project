///
/// \file main.cpp
/// \brief Main application
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 1.0.0
///

#define W_HEIGHT 810
#define W_WIDTH 1290

#include <iostream>
#include <fstream>

#include "SkeletonViewer.h"

int main(int argc, char **argv)
{
	// Instanciate a mesh viewer and attach the input mesh
	SkeletonViewer viewer{"Skeleton Viewer", W_WIDTH, W_HEIGHT};

	// Start main window loop
	viewer.run();
	return 0;
}
