#include "pch.h"
#include "../11.9/Package.h"
#include "../11.9/TwoDayPackage.h"
#include "../11.9/OvernightPackage.h"

class Test11_9 : public ::testing::Test
{
public:
	//Need to be modified!
	Test11_9()
		:sender("G", "Honey Road No.1", "HG", "HB", "242424"),
		recipient("C", "Scientist Roat No.1", "WH", "HB", "666666"),
		weight(100),
		costPerOunce(100),
		flatFee(99),
		feePerOunce(100),
		pack(sender, recipient, weight, costPerOunce),
		twoDayPack(sender, recipient, weight, costPerOunce, flatFee),
		overnightPackage(sender, recipient, weight, costPerOunce, feePerOunce)
	{
	};

	double weight;
	double costPerOunce;
	double flatFee;
	double feePerOunce;
	Person sender;
	Person recipient;
	Package pack;
	TwoDayPackage twoDayPack;
	OvernightPackage overnightPackage;

	void SetUp() override
	{
		
	}

	void TearDown() override
	{

	}
};

TEST_F(Test11_9, TestPackage) 
{
	double cost = 10000;
	EXPECT_EQ(cost, pack.calculateCost());
}

TEST_F(Test11_9, TestTwoDayPackGetFlatFee)
{
	double flatFee = 99;
	EXPECT_EQ(flatFee, twoDayPack.getFlatFee());
}

TEST_F(Test11_9, TestTwoDayPackCalculateCost)
{
	double cost = 10099;
	EXPECT_EQ(cost, twoDayPack.calculateCost());
}

TEST_F(Test11_9, TestOvernightPackCalculateCost)
{
	double cost = 20000;
	EXPECT_EQ(cost, overnightPackage.calculateCost());
}