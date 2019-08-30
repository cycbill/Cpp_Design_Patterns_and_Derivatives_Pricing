#ifndef PAYOFF_EXR_2_2_H
#define PAYOFF_EXR_2_2_H

class PayOff
{
public:
	enum OptionType { doubledigital };
	PayOff(double LowStrike_, double HighStrike_, OptionType TheOptionsType_);
	double operator()(double Spot) const;

private:
	double LowStrike, HighStrike;
	OptionType TheOptionsType;
};

#endif // !PAYOFF_EXR_2_2_H
