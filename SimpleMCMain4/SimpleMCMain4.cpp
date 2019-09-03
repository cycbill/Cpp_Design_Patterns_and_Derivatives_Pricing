/*
requires
	PayOff2.cpp
	Random1.cpp
	SimpleMC2.cpp
*/

#include "../_headers/SimpleMC2.h"
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

	unsigned long optionType;
	std::cout << "Enter 0 for call, otherwise put: ";
	std::cin >> optionType;

	PayOff* thePayOffPtr;

	if (optionType == 0)
		thePayOffPtr = new PayOffCall(Strike);
	else
		thePayOffPtr = new PayOffPut(Strike);

	double result = SimpleMonteCarlo2(*thePayOffPtr,
		Expiry,
		Spot,
		Vol,
		r,
		NumberOfPaths);

	std::cout << "\nthe price is " << result << std::endl;

	double tmp;
	std::cin >> tmp;

	delete thePayOffPtr;

	return 0;
}