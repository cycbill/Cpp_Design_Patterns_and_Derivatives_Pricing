#include "../_headers/PowerOption.h"
#include <algorithm>
#include <cmath>

PayOffPowerCall::PayOffPowerCall(double Power_, double Strike_)
	: Power(Power_), Strike(Strike_) {}

double PayOffPowerCall::operator()(double Spot) const
{
	return std::max(pow(Spot, Power) - Strike, 0.0);
}

PayOffPowerPut::PayOffPowerPut(double Power_, double Strike_)
	: Power(Power_), Strike(Strike_) {}

double PayOffPowerPut::operator()(double Spot) const
{
	return std::max(Strike - pow(Spot, Power), 0.0);
}