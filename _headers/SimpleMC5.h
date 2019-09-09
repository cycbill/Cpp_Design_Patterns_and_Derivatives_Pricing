#ifndef SIMPLEMC5_H
#define SIMPLEMC5_H

#include "../_headers/Vanilla3.h"

double SimpleMonteCarlo3(const VanillaOption& TheOption,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths);

#endif // !SIMPLEMC5_H
