#pragma once
#include "Package.h"

namespace name12_13 {

	class TwoDayPackage : public Package
	{
	public:
		explicit TwoDayPackage(Person& Sender, Person& Recipient, double Weight,
			double CostPerOunce, double FlatFee);
		virtual ~TwoDayPackage() {};

		virtual double calculateCost(void) const override;

		double getFlatFee(void) const
		{
			return flatFee;
		}

		void setFlatFee(double FlatFee);

	private:
		double flatFee;
	};

}