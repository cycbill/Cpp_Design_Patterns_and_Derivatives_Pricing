/*
requires
		PayOff1.cpp
		Random1.cpp
		SimpleMC.cpp
*/

#include "SimpleMC_Exr_2_2.h"
#include <iostream>
#include <chrono>

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	double Expiry;
	double LowStrike;
	double HighStrike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	Expiry = 1.0;
	LowStrike = 1.28;
	HighStrike = 1.32;
	Spot = 1.30;
	Vol = 0.1;
	r = 0.04;
	NumberOfPaths = 10000;

	PayOff doubleDigitalPayOff(LowStrike, HighStrike, PayOff::doubledigital);

	double resultDoubleDigital = SimpleMonteCarlo2(doubleDigitalPayOff,
		Expiry,
		Spot,
		Vol,
		r,
		NumberOfPaths);


	std::cout << "the prices are " << resultDoubleDigital
		<< " for the double digital\n";

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "execution time is " << duration.count() << " microseconds." << std::endl;

	std::cin.get();
	return 0;
}