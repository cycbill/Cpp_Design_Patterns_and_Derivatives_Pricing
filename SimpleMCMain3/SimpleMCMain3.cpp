/*
requires
		PayOff2.cpp
		Random1.cpp
		SimpleMC2.cpp
*/

#include "../_headers/SimpleMC2.h"
#include<iostream>

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

	PayOffCall callPayOff(Strike);
	PayOffPut putPayOff(Strike);

	double resultCall = SimpleMonteCarlo2(callPayOff,
		Expiry,
		Spot,
		Vol,
		r,
		NumberOfPaths);

	double resultPut = SimpleMonteCarlo2(putPayOff,
		Expiry,
		Spot,
		Vol,
		r,
		NumberOfPaths);

	std::cout << "the prices are " << resultCall
		<< " for the call and "
		<< resultPut
		<< " for the put\n";

	std::cin.get();
	return 0;
}