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

// Test 
#define TEST false

#include "SkeletonViewer.h"
#include "SkeletonTester.h"

int main(int argc, char **argv)
{
	if(!TEST)
	{
		SkeletonViewer viewer("Skeleton Viewer", W_WIDTH, W_HEIGHT, QS_TRADEOFF, MCS_TRADEOFF);
		viewer.run();
	} else {
		SkeletonTester tester(QS_TRADEOFF, MCS_TRADEOFF);
		tester.start("./data/13_octopus.off");
		tester.start("./data/108_twirl.off");
		tester.start("./data/178_raptor.off");
		tester.start("./data/189_filigree.off");
		tester.start("./data/189_filigree-low.off");
		tester.start("./data/1441_Sketched-Brunnen.off");
		tester.start("./data/hand_bones-connected.off");
		tester.start("./data/knot108s.off");
		tester.start("./data/simple_cube.off");
		tester.start("./data/simple_cylinder.off");
		tester.start("./data/simple_torus.off");
	}

	return 0;
}
