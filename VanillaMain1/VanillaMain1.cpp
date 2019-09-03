/*
requires DoubleDigital.cpp
		PayOff2.cpp
		Random1.cpp
		SimpleMC3.cpp
		Vanilla1.cpp
*/

#include "../_headers/SimpleMC3.h"
#include "../_headers/DoubleDigital.h"
#include "../_headers/Vanilla1.h"
#include <iostream>

int main()
{
	double Expiry;
	double Low, Up;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	Expiry = 1.0;
	Low = 1.28;
	Up = 1.32;
	Spot = 1.30;
	Vol = 0.1;
	r = 0.04;
	NumberOfPaths = 10000;

	PayOffDoubleDigital thePayOff(Low, Up);
	
	VanillaOption theOption(thePayOff, Expiry);

	double result = SimpleMonteCarlo3(theOption,
		Spot,
		Vol,
		r,
		NumberOfPaths);

	std::cout << "the price is " << result << std::endl;

	double tmp;
	std::cin >> tmp;

	return 0;
}
