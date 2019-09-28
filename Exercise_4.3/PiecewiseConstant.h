#ifndef PIECEWISECONSTANT_H
#define PIECEWISECONSTANT_H

#include "../_headers/Parameters.h"
#include "../_headers/Arrays.h"

class PiecewiseConstant : public ParametersInner
{
public:
	PiecewiseConstant(MJArray maturities, MJArray constants);
	
	virtual ParametersInner* clone() const;
	virtual double Integral(double time1, double time2) const;
	virtual double IntegralSquare(double time1, double time2) const;

private:
	MJArray Maturities;
	MJArray Constants;
	MJArray ConstantsSquare;
};

#endif // !PIECEWISECONSTANT_H