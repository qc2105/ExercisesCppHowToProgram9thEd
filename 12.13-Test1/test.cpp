#include "pch.h"
#include "../12.13/TwoDayPackage.h"
#include "../12.13/OvernightPackage.h"

class TestPolymorphism : public ::testing::Test
{
protected:
	TestPolymorphism()
		:Sender("Chuan Qin", "Some Place No.1", "San Diego", "CA", "92121"),
		Recipient("Chuan Qin", "Some Place No.2", "Wuhan", "Hubei", "439000"),
		Weight(100),
		CostPerOunce(100),
		FlatFee(100),
		tdp(Sender, Recipient, Weight, CostPerOunce, FlatFee),
		onp(Sender, Recipient, Weight, CostPerOunce, CostPerOunce * 2)
	{
	};

	virtual ~TestPolymorphism()
	{
	};

	Person Sender;
	Person Recipient;
	double Weight;
	double CostPerOunce;
	double FlatFee;
	TwoDayPackage tdp;
	OvernightPackage onp;
};


TEST_F(TestPolymorphism, TestTwoDayPackCalculateCost)
{
	double costExp = 10100;
	Package *pPackage = nullptr;
	pPackage = &tdp;
	EXPECT_EQ(costExp, pPackage->calculateCost());
}

TEST_F(TestPolymorphism, TestOvernightPackCalculateCost)
{
	double cosetExp = 30000;
	Package *pPackage = nullptr;
	pPackage = &onp;
	EXPECT_EQ(cosetExp, pPackage->calculateCost());
}
