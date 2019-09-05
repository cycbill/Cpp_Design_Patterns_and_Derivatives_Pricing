#ifndef VANILLA_2_H
#define VANILLA_2_H

#include "../_headers/PayOff3.h"

class VanillaOption
{
public:
	VanillaOption(const PayOff& ThePayOff_, double Expiry_);
	VanillaOption(const VanillaOption& original);
	VanillaOption& operator=(const VanillaOption& original);
	~VanillaOption();

	double GetExpiry() const;
	double OptionPayOff(double Spot) const;
private:
	double Expiry;
	PayOff* ThePayOffPtr;
};

#endif // !VANILLA_2_H
