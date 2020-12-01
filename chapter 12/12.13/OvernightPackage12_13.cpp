#include "OvernightPackage.h"

namespace name12_13 {

	OvernightPackage::OvernightPackage(Person& Sender, Person& Recipient, double Weight,
		double CostPerOunce, double FeePerOunce)
		:Package(Sender, Recipient, Weight, CostPerOunce)
	{
		setFeePerOunce(FeePerOunce);
	}

	void OvernightPackage::setFeePerOunce(double FeePerOunce)
	{
		if (FeePerOunce > 0)
		{
			feePerOunce = FeePerOunce;
			return;
		}
		throw std::invalid_argument("FeePerOunce must be positive\n");
	}

}