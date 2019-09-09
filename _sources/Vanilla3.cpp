#include "../_headers/Vanilla3.h"

VanillaOption::VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_)
	: ThePayoff(ThePayOff_), Expiry(Expiry_) {}

double VanillaOption::GetExpiry() const
{
	return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
	return ThePayoff(Spot);
}