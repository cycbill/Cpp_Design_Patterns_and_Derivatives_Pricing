#ifndef PAYOFF_EXR_2_1_H
#define PAYOFF_EXR_2_1_H

class PayOff
{
public:
	enum OptionType { digitalcall, digitalput };
	PayOff(double Strike_, OptionType TheOptionsType_);
	double operator()(double Spot) const;

private:
	double Strike;
	OptionType TheOptionsType;
};

#endif // !PAYOFF_EXR_2_1_H
