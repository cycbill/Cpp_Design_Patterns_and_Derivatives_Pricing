/*
requires PayOff3.cpp,
		Random1.cpp,
		SimpleMC6.cpp
		Vanilla3.cpp
		Parameters.cpp
*/

#include "../_headers/SimpleMC6.h"
#include "../_headers/Vanilla3.h"
#include "../_headers/Parameters.h"
#include "../_headers/Arrays.h"
#include "PiecewiseConstant.h"
#include <iostream>

int main()
{
	double Expiry;
	double Strike;
	double Spot;
	double r;
	unsigned long NumberOfPaths;

	Expiry = 1.0;
	Strike = 1.32;
	Spot = 1.30;
	r = 0.04;
	NumberOfPaths = 10000;

	unsigned long size = 10;
	MJArray Mat(size);
	MJArray Vol(size);
	Mat = 1.0;
	for (unsigned long i = 0; i < size; i++)
	{
		Mat[i] = 0.1 * static_cast<double>(i);
		Vol[i] = 0.1 + 0.000002 * static_cast<double>(i);
	}

	PiecewiseConstant VolParam(Mat, Vol);
	ParametersConstant rParam(r);

	PayOffCall thePayOff(Strike);

	VanillaOption theOption(thePayOff, Expiry);


	double result = SimpleMonteCarlo4(theOption,
		Spot, VolParam, rParam, NumberOfPaths);

	std::cout << "the call price is " << result << std::endl;

	VanillaOption secondOption(theOption);	//secondOption clones from theOption.

	result = SimpleMonteCarlo4(secondOption,
		Spot, VolParam, rParam, NumberOfPaths);

	std::cout << "the call price is " << result << std::endl;

	PayOffPut otherPayOff(Strike);
	VanillaOption thirdOption(otherPayOff, Expiry);
	theOption = thirdOption;	// theOption clones from thirdOption.

	result = SimpleMonteCarlo4(theOption,
		Spot, VolParam, rParam, NumberOfPaths);

	std::cout << "the put price is " << result << std::endl;

	double tmp;
	std::cin >> tmp;

	return 0;

}