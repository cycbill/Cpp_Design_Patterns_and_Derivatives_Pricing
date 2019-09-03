/*
requires PowerOption.cpp
		PayOff2.cpp
		Random1.cpp
		SimpleMC2.cpp
*/

#include "../_headers/SimpleMC2.h"
#include "../_headers/PowerOption.h"
#include <iostream>

int main()
{
	double Expiry;
	double Power;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	Expiry = 1.0;
	Power = 3.0;
	Strike = 1.32;
	Spot = 1.30;
	Vol = 0.1;
	r = 0.04;

	NumberOfPaths = 10000;

	PayOffPowerCall thePayOff(Power, Strike);

	double result = SimpleMonteCarlo2(thePayOff,
		Expiry,
		Spot,
		Vol,
		r,
		NumberOfPaths);

	std::cout << "the price is " << result << std::endl;

	std::cin.get();
	return 0;
}