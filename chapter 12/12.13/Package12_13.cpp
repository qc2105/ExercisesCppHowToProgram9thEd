#include "Package.h"
#include <stdexcept>

namespace name12_13 {

	Package::Package(Person& Sender, Person& Recipient, double Weight, double CostPerOunce)
		:sender(Sender),
		recipient(Recipient)
	{
		setWeight(Weight);
		setCostPerOunce(CostPerOunce);
	}

	void Package::setWeight(const double weightInput)
	{
		if (weightInput > 0)
		{
			weight = weightInput;
			return;
		}

		throw std::invalid_argument("weight must be positive\n");
	}
	void Package::setCostPerOunce(const double valueInput)
	{
		if (valueInput > 0)
		{
			costPerOunce = valueInput;
			return;
		}

		throw std::invalid_argument("costPerOunce should be positive\n");
	}

}