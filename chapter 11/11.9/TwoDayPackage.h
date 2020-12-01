#pragma once
#include "Package.h"
class TwoDayPackage : public Package
{
public:
	explicit TwoDayPackage(Person & Sender, Person & Recipient, double Weight, 
		double CostPerOunce, double FlatFee);

	double calculateCost(void) const;

	double getFlatFee(void) const
	{
		return flatFee;
	}

	void setFlatFee(double FlatFee);

private:
	double flatFee;
};

