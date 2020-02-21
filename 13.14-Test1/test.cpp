#include "pch.h"
#include "../13.14/PhoneNumber.h"
#include <sstream>

class PhoneNumberInputTest : public ::testing::Test
{
protected:
	PhoneNumberInputTest()
		:validInput("(213) 456-7890"),
		invalidLengthInput1("(213) 456-789"),
		invalidLengthInput2("(213) 456-78900"),
		invalidAreaCodeWithLeading0("(013) 456-7890"),
		invalidAreaCodeWithLeading1("(113) 456-7890"),
		invalidExchangeCodeWithLeading0("(213) 056-7890"),
		invalidExchangeCodeWithLeading1("(213) 156-7890")
	{

	}
	virtual ~PhoneNumberInputTest()
	{

	}

	PhoneNumber phone;
	std::string validInput;
	std::string invalidLengthInput1;
	std::string invalidLengthInput2;
	std::string invalidAreaCodeWithLeading0;
	std::string invalidAreaCodeWithLeading1;
	std::string invalidExchangeCodeWithLeading0;
	std::string invalidExchangeCodeWithLeading1;
	// invalid old area code without middle 0 or 1 will be generated in the test.
};

TEST_F(PhoneNumberInputTest, TestValidInput)
{
	std::stringstream  input(validInput);
	EXPECT_TRUE(input >> phone);
}

TEST_F(PhoneNumberInputTest, TestInvalidLength)
{
	std::stringstream input1(invalidLengthInput1);
	EXPECT_FALSE(input1 >> phone);

	std::stringstream input2(invalidLengthInput2);
	EXPECT_FALSE(input2 >> phone);
}

TEST_F(PhoneNumberInputTest, TestInvalidAreaCode)
{
	std::stringstream input1(invalidAreaCodeWithLeading0);
	EXPECT_FALSE(input1 >> phone);

	std::stringstream input2(invalidAreaCodeWithLeading1);
	EXPECT_FALSE(input2 >> phone);
}

TEST_F(PhoneNumberInputTest, TestInvalidExchangeCode)
{
	std::stringstream input1(invalidExchangeCodeWithLeading0);
	EXPECT_FALSE(input1 >> phone);

	std::stringstream input2(invalidExchangeCodeWithLeading1);
	EXPECT_FALSE(input2 >> phone);
}

TEST_F(PhoneNumberInputTest, TestInvalidOldAreaCode)
{
	for (size_t i = 2; i < 10; ++i)
	{
		std::string invalidMidleDigit = std::to_string(i);
		validInput.at(2) = invalidMidleDigit.at(0);
		std::stringstream invalidStr(validInput);
		EXPECT_FALSE(invalidStr >> phone);
	}
}