// ***************************************************
// Exercise 1.2 Modify the program given to price double digitals.
// ***************************************************

#include "../_headers/Random1.h"
#include <iostream>
#include <cmath>

double SimpleMonteCarlo1(double Expiry,
	double LowStrike,
	double HighStrike,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths)
{
	double variance = Vol * Vol*Expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	double movedSpot = Spot * exp(r * Expiry + itoCorrection);
	double thisSpot;
	double runningSum = 0;
	double thisPayoff;

	for (unsigned long i = 0; i < NumberOfPaths; i++)
	{
		double thisGaussian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		if ((thisSpot >= LowStrike) && (thisSpot <= HighStrike))
			thisPayoff = 1.0;
		else
			thisPayoff = 0.0;
		runningSum += thisPayoff;
	}

	double mean = runningSum / NumberOfPaths;
	mean *= exp(-r * Expiry);
	return mean;
}

int main()
{
	double Expiry;
	double LowStrike;
	double HighStrike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	Expiry = 1.0;
	LowStrike = 1.30;
	HighStrike = 1.35;
	Spot = 1.32;
	Vol = 0.1;
	r = 0.04;
	NumberOfPaths = 10000;

	double result = SimpleMonteCarlo1(Expiry,
		LowStrike,
		HighStrike,
		Spot,
		Vol,
		r,
		NumberOfPaths);

	std::cout << "the price is " << result << std::endl;

	std::cin.get();
	return 0;
}