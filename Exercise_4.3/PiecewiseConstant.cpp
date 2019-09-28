#include "PiecewiseConstant.h"



PiecewiseConstant::PiecewiseConstant(MJArray maturities, MJArray constants)
{
	Constants = constants;
	ConstantsSquare = constants;
	ConstantsSquare *= constants;
}

ParametersInner* PiecewiseConstant::clone() const
{
	return new PiecewiseConstant(*this);
}

double PiecewiseConstant::Integral(double time1, double time2) const
{
	if (time1 == time2)
		return 0;
	double runningSum = 0;
	unsigned long idx1 = 0;
	while ((time1 > Maturities[idx1]) && (idx1 < Maturities.size()))
		idx1++;
	unsigned long idx2 = idx1;
	while ((time2 > Maturities[idx2]) && (idx2 < Maturities.size()))
	{
		if (idx2 - idx1 > 0)
			runningSum += (Maturities[idx2] - Maturities[idx2 - 1]) * Constants[idx2];
		idx2++;
	}
	if (idx2 - idx1 > 0)
	{
		runningSum += (Maturities[idx1] - time1) * Constants[idx1];
		runningSum += (time2 - Maturities[idx2 - 1]) * Constants[idx2 - 1];
	}
	return runningSum;
}

double PiecewiseConstant::IntegralSquare(double time1, double time2) const
{
	if (time1 == time2)
		return 0;
	double runningSum = 0;
	unsigned long idx1 = 0;
	while ((time1 > Maturities[idx1]) && (idx1 < Maturities.size()))
		idx1++;
	unsigned long idx2 = idx1;
	while ((time2 > Maturities[idx2]) && (idx2 < Maturities.size()))
	{
		if (idx2 - idx1 > 0)
			runningSum += (Maturities[idx2] - Maturities[idx2 - 1]) * ConstantsSquare[idx2];
		idx2++;
	}
	if (idx2 - idx1 > 0)
	{
		runningSum += (Maturities[idx1] - time1) * ConstantsSquare[idx1];
		runningSum += (time2 - Maturities[idx2 - 1]) * ConstantsSquare[idx2 - 1];
	}
	return runningSum;
}