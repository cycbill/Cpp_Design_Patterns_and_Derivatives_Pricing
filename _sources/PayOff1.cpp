#include "../_headers/PayOff1.h"
#include <algorithm>

PayOff::PayOff(double Strike_, OptionType TheOptionType_)
	: Strike(Strike_), TheOptionsType(TheOptionType_) {}

double PayOff::operator()(double Spot) const
{
	switch (TheOptionsType)
	{
	case call:
		return std::max(Spot - Strike, 0.0);
	case put:
		return std::max(Strike - Spot, 0.0);
	default:
		throw("unknown option type found.");
	}
}