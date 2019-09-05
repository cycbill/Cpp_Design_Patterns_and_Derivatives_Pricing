#include "../_headers/Vanilla2.h"

VanillaOption::VanillaOption(const PayOff& ThePayOff_, double Expiry_)
	: Expiry(Expiry_)
{
	ThePayOffPtr = ThePayOff_.clone();
}

double VanillaOption::GetExpiry() const
{
	return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
	return (*ThePayOffPtr)(Spot);
}

VanillaOption::VanillaOption(const VanillaOption& original)
{
	Expiry = original.Expiry;
	ThePayOffPtr = original.ThePayOffPtr->clone();
}