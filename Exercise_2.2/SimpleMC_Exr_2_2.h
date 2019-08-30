#ifndef SIMPLEMC_EXR_2_2_H
#define SIMPLEMC_EXR_2_2_H

#include "PayOff1_Exr_2_2.h"

double SimpleMonteCarlo2(const PayOff& thePayOff,
	double Expiry,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths);

#endif // !SIMPLEMC_EXR_2_2_H
