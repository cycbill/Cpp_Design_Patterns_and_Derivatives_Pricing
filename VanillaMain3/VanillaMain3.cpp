/*
requires PayOff3.cpp,
		Random1.cpp,
		SimpleMC4.cpp
		Vanilla2.cpp
*/

#include "../_headers/SimpleMC5.h"
#include "../_headers/Vanilla3.h"
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

	double result = SimpleMonteCarlo3(theOption,
		Spot, Vol, r, NumberOfPaths);

	std::cout << "the call price is " << result << std::endl;

	VanillaOption secondOption(theOption);	//secondOption clones from theOption.

	result = SimpleMonteCarlo3(secondOption,
		Spot, Vol, r, NumberOfPaths);

	std::cout << "the call price is " << result << std::endl;

	PayOffPut otherPayOff(Strike);
	VanillaOption thirdOption(otherPayOff, Expiry);
	theOption = thirdOption;	// theOption clones from thirdOption.

	result = SimpleMonteCarlo3(theOption,
		Spot, Vol, r, NumberOfPaths);

	std::cout << "the put price is " << result << std::endl;

	double tmp;
	std::cin >> tmp;

	return 0;

}