#ifndef SIMPLEMC6_H
#define SIMPLEMC6_H

#include "../_headers/Vanilla3.h"
#include "../_headers/Parameters.h"

double SimpleMonteCarlo4(const VanillaOption& TheOption,
	double Spot,
	const Parameters& Vol,
	const Parameters& r,
	unsigned long NumberOfPaths);

#endif // !SIMPLEMC6_H
