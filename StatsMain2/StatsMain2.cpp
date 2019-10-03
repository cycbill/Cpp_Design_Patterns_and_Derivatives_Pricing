/*
uses source files
	MCStatistics.cpp
	Parameters.cpp
	PayOff3.cpp
	PayOffBridge.cpp
	Random1.cpp
	SimpleMC7.cpp
	Vanilla3.cpp
*/

#include "../_headers/SimpleMC7.h"
#include "../_headers/Vanilla3.h"
#include "../_headers/MCStatistics.h"
#include "../_headers/ConvergenceTable.h"
#include <iostream>

int main()
{
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	Expiry = 1.0;
	Strike = 1.32;
	Spot = 1.30;
	Vol = 0.1;
	r = 0.04;
	NumberOfPaths = 10000;

	PayOffCall thePayOff(Strike);
	VanillaOption theOption(thePayOff, Expiry);

	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);

	StatisticsMean gatherer;
	ConvergenceTable gathererTwo(gatherer);

	SimpleMonteCarlo5(theOption, Spot, VolParam, rParam, NumberOfPaths, gathererTwo);

	std::vector<std::vector<double> > results = gathererTwo.GetResultsSoFar();

	std::cout << "\nFor the call price the results are \n";

	for (unsigned long i = 0; i < results.size(); i++)
	{
		for (unsigned long j = 0; j < results[i].size(); j++)
			std::cout << results[i][j] << " ";

		std::cout << std::endl;
	}

	double tmp;
	std::cin >> tmp;
	return 0;
}
