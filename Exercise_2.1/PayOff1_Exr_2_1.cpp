#include "PayOff1_Exr_2_1.h"
#include <algorithm>

PayOff::PayOff(double Strike_, OptionType TheOptionsType_)
	: Strike(Strike_), TheOptionsType(TheOptionsType_) {}

double PayOff::operator()(double Spot) const
{
	switch (TheOptionsType)
	{
	case digitalcall:
		return Spot >= Strike ? 1.0 : 0.0;
	case digitalput:
		return Spot <= Strike ? 1.0 : 0.0;
	default:
		throw("unknown option type found.");
	}
}