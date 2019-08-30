#include "PayOff1_Exr_2_2.h"
#include <algorithm>

PayOff::PayOff(double LowStrike_, double HighStrike_, OptionType TheOptionsType_)
	: LowStrike(LowStrike_), HighStrike(HighStrike_), TheOptionsType(TheOptionsType_) {}

double PayOff::operator()(double Spot) const
{
	switch (TheOptionsType)
	{
	case doubledigital:
		if ((Spot >= LowStrike) && (Spot <= HighStrike))
			return 1.0;
		else
			return 0.0;
	default:
		throw("unknown option type found.");
	}
}