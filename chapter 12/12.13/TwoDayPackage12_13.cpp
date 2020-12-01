#include "TwoDayPackage.h"

namespace name12_13 {

	TwoDayPackage::TwoDayPackage(Person& Sender, Person& Recipient, double Weight,
		double CostPerOunce, double FlatFee)
		:Package(Sender, Recipient, Weight, CostPerOunce)
	{
		setFlatFee(FlatFee);
	}

	double TwoDayPackage::calculateCost(void) const
	{
		return Package::calculateCost() + getFlatFee();
	}

	void TwoDayPackage::setFlatFee(double FlatFee)
	{
		if (FlatFee > 0)
		{
			flatFee = FlatFee;
			return;
		}
		throw std::invalid_argument("FlatFee must be positive\n");
	}

}