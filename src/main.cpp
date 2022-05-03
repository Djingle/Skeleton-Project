///
/// \file main.cpp
/// \brief Main application
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 1.0.0
///

// Window size
#define W_HEIGHT 810
#define W_WIDTH 1290

// Algorithm parameter
#define QS_TRADEOFF 100
#define MCS_TRADEOFF 100

#include "SkeletonViewer.h"

int main(int argc, char **argv)
{
	// Instanciate a mesh viewer and attach the input mesh
	SkeletonViewer viewer("Skeleton Viewer", W_WIDTH, W_HEIGHT, QS_TRADEOFF, MCS_TRADEOFF);

	// Start main window loop
	viewer.run();
	return 0;
}
