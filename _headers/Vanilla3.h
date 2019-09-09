#ifndef VANILLA_3_H
#define VANILLA_3_H

#include "../_headers/PayOffBridge.h"

class VanillaOption
{
public:
	VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_);
	
	double OptionPayOff(double Spot) const;
	double GetExpiry() const;

private:
	double Expiry;
	PayOffBridge ThePayoff;

};

#endif // !VANILLA_3_H
