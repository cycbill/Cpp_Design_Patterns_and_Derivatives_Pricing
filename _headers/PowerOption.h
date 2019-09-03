#ifndef POWEROPTION_H
#define POWEROPTION_H

#include "../_headers/PayOff2.h"

class PayOffPowerCall : public PayOff
{
public:
	PayOffPowerCall(double Power_, double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffPowerCall() {};
private:
	double Power;
	double Strike;
};

class PayOffPowerPut : public PayOff
{
public:
	PayOffPowerPut(double Power_, double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffPowerPut() {};
private:
	double Power;
	double Strike;
};

#endif // !POWEROPTION_H
