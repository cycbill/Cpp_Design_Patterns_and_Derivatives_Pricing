/*
requires PowerOption.cpp
		PayOff2.cpp
		Random1.cpp
		SimpleMC2.cpp
*/

#include "../_headers/SimpleMC2.h"
#include "../_headers/PayOff2.h"
#include "../_headers/PowerOption.h"
#include "../_headers/DoubleDigital.h"
#include <iostream>
#include <string>

int main()
{
	double Expiry;
	double Power;
	double Strike;
	double Low, Up;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	Expiry = 1.0;
	Spot = 1.30;
	Vol = 0.1;
	r = 0.04;
	NumberOfPaths = 10000;

	PayOff* thePayOffPtr;
	std::string PayOffName;

	std::cout << "Type in the payoff (Call, Put, DoubleDigital, PowerCall, PowerPut): " << std::endl;
	std::getline(std::cin, PayOffName);

	if (PayOffName == "Call") {
		std::cout << "Input Strike: ";
		std::cin >> Strike;
		thePayOffPtr = new PayOffCall(Strike);
	}
	else if (PayOffName == "Put") {
		std::cout << "Input Strike: ";
		std::cin >> Strike;
		thePayOffPtr = new PayOffPut(Strike);
	}
	else if (PayOffName == "PowerCall") {
		std::cout << "Input Power and Strike: ";
		std::cin >> Power >> Strike;
		thePayOffPtr = new PayOffPowerCall(Power, Strike);
	}
	else if (PayOffName == "PowerPut") {
		std::cout << "Input Power and Strike: ";
		std::cin >> Power >> Strike;
		thePayOffPtr = new PayOffPowerPut(Power, Strike);
	}
	else if (PayOffName == "DoubleDigital") {
		std::cout << "Input Lower Level and Upper Level: ";
		std::cin >> Low >> Up;
		thePayOffPtr = new PayOffPowerPut(Low, Up);
	}
	else
		throw("Payoff type is not available!");

	double result = SimpleMonteCarlo2(*thePayOffPtr,
		Expiry,
		Spot,
		Vol,
		r,
		NumberOfPaths);

	std::cout << "the price is " << result << std::endl;

	double tmp;
	std::cin >> tmp;

	delete thePayOffPtr;
	return 0;
}