#ifndef SIMPLEMC7_H
#define SIMPLEMC7_H

#include "../_headers/Vanilla3.h"
#include "../_headers/Parameters.h"
#include "../_headers/MCStatistics.h"

void SimpleMonteCarlo5(const VanillaOption& TheOption,
	double Spot,
	const Parameters& Vol,
	const Parameters& r,
	unsigned long NumberOfPaths,
	StatisticsMC& gatherer);
#endif // !SIMPLEMC7_H
