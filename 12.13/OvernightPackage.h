#pragma once
#include "Package.h"
class OvernightPackage : 
	public Package
{
public:
	OvernightPackage(Person &Sender, Person &Recipient, double Weight,
		double CostPerOunce, double FeePerOunce);
	virtual ~OvernightPackage() {};
	
	virtual double calculateCost(void) const override
	{
		return Package::calculateCost() + Package::getWeight() * getFeePerOunce();
	}

	double getFeePerOunce(void) const
	{
		return feePerOunce;
	}
	void setFeePerOunce(double FeePerOunce);
private:
	double feePerOunce;
};

