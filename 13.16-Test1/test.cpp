#include "pch.h"
#include "../13.16/Complex.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>


class TestComplex : public ::testing::Test
{
protected:

	TestComplex()
	{
		char * validInputsArray[] = {
			"3 + 8i",
			"+3 + 8i",
			"-3 - 8i",
			"-3 + 8i",
			"+3 - 8i",
			"3 - 8i",
			"3",
			"8i",
			"-3",
			"-8i",
			"0i",
			"i",
			"5 + i"
		};

		char *invalidInputsArray[] = {
			"",
			"+",
			"-",
			"+3q",
			"-3t",
			"+-",
			"--"
		};

		for (size_t i = 0; i < sizeof(validInputsArray) / sizeof(char *); ++i)
		{
			validInputs.push_back(std::stringstream(validInputsArray[i]));
		}
		for (size_t i = 0; i < sizeof(invalidInputsArray) / sizeof(char *); ++i)
		{
			invalidInputs.push_back(std::stringstream(invalidInputsArray[i]));
		}
	}
	virtual ~TestComplex() {}

	Complex complex;
	std::vector<std::stringstream> validInputs;
	std::vector<std::stringstream> invalidInputs;
};

TEST_F(TestComplex, TestEqual)
{
	Complex c1(1, 2), c2(1, 2);
	EXPECT_EQ(c1, c2);
}

TEST_F(TestComplex, TestOutPut0)
{
	Complex c0(3, 8);
	std::stringstream out;
	out << c0;
	EXPECT_EQ("3+8i", out.str());
}

TEST_F(TestComplex, TestOutPut1)
{
	Complex c1(-3, -8);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("-3-8i", out.str());
}

TEST_F(TestComplex, TestOutPut2)
{
	Complex c1(-3, 8);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("-3+8i", out.str());
}

TEST_F(TestComplex, TestOutPut3)
{
	Complex c1(3, -8);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("3-8i", out.str());
}

TEST_F(TestComplex, TestOutPut4)
{
	Complex c1(3, 0);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("3", out.str());
}

TEST_F(TestComplex, TestOutPut5)
{
	Complex c1(0, 8);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("8i", out.str());
}

TEST_F(TestComplex, TestOutPut6)
{
	Complex c1(-3, 0);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("-3", out.str());
}

TEST_F(TestComplex, TestOutPut7)
{
	Complex c1(0, -8);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("-8i", out.str());
}

TEST_F(TestComplex, TestOutPut8)
{
	Complex c1(0, 0);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("0", out.str());
}

TEST_F(TestComplex, TestOutPut9)
{
	Complex c1(0, 1);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("i", out.str());
}

TEST_F(TestComplex, TestOutPut10)
{
	Complex c1(5, 1);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("5+i", out.str());
}

TEST_F(TestComplex, TestValidInput0)
{
	EXPECT_TRUE(validInputs.at(0) >> complex);
	Complex c1(3, 8);
	EXPECT_EQ(c1, complex);
}

TEST_F(TestComplex, TestValidInput1)
{
	EXPECT_TRUE(validInputs.at(1) >> complex);
	Complex c1(3, 8);
	EXPECT_EQ(c1, complex);
}

TEST_F(TestComplex, TestValidInput2)
{
	EXPECT_TRUE(validInputs.at(2) >> complex);
	Complex c2(-3, -8);
	EXPECT_EQ(c2, complex);
}

TEST_F(TestComplex, TestValidInput3)
{
	EXPECT_TRUE(validInputs.at(3) >> complex);
	Complex c3(-3, +8);
	EXPECT_EQ(c3, complex);
}
	
TEST_F(TestComplex, TestValidInput4)
{
	EXPECT_TRUE(validInputs.at(4) >> complex);
	Complex c4(+3, -8);
	EXPECT_EQ(c4, complex);
}

TEST_F(TestComplex, TestValidInput5)
{
	EXPECT_TRUE(validInputs.at(5) >> complex);
	Complex c4(+3, -8);
	EXPECT_EQ(c4, complex);
}

TEST_F(TestComplex, TestValidInput6)
{
	EXPECT_TRUE(validInputs.at(6) >> complex);
	Complex c5(3, 0);
	EXPECT_EQ(c5, complex);
}
	
TEST_F(TestComplex, TestValidInput7)
{
	EXPECT_TRUE(validInputs.at(7) >> complex);
	Complex c6(0, 8);
	EXPECT_EQ(c6, complex);
}
	
TEST_F(TestComplex, TestValidInput8)
{
	EXPECT_TRUE(validInputs.at(8) >> complex);
	Complex c7(-3, 0);
	EXPECT_EQ(c7, complex);
}

TEST_F(TestComplex, TestValidInput9)
{
	EXPECT_TRUE(validInputs.at(9) >> complex);
	Complex c8(0, -8);
	EXPECT_EQ(c8, complex);
}

TEST_F(TestComplex, TestValidInput10)
{
	EXPECT_TRUE(validInputs.at(10) >> complex);
	Complex c8(0, 0);
	EXPECT_EQ(c8, complex);
}

TEST_F(TestComplex, TestValidInput11)
{
	EXPECT_TRUE(validInputs.at(11) >> complex);
	Complex c8(0, 1);
	EXPECT_EQ(c8, complex);
}

TEST_F(TestComplex, TestValidInput12)
{
	EXPECT_TRUE(validInputs.at(12) >> complex);
	Complex c8(5, 1);
	EXPECT_EQ(c8, complex);
}

TEST_F(TestComplex, TestInvalid0)
{
	EXPECT_FALSE(invalidInputs.at(0) >> complex);
	std::stringstream output;
	EXPECT_FALSE(output << complex);
	EXPECT_TRUE(output.str().empty());
}

TEST_F(TestComplex, TestInvalid1)
{
	EXPECT_FALSE(invalidInputs.at(1) >> complex);
	std::stringstream output;
	EXPECT_FALSE(output << complex);
	EXPECT_TRUE(output.str().empty());
}

TEST_F(TestComplex, TestInvalid2)
{
	EXPECT_FALSE(invalidInputs.at(2) >> complex);
	std::stringstream output;
	EXPECT_FALSE(output << complex);
	EXPECT_TRUE(output.str().empty());
}

TEST_F(TestComplex, TestInvalid3)
{
	EXPECT_FALSE(invalidInputs.at(3) >> complex);
	std::stringstream output;
	EXPECT_FALSE(output << complex);
	EXPECT_TRUE(output.str().empty());
}

TEST_F(TestComplex, TestInvalid4)
{
	EXPECT_FALSE(invalidInputs.at(4) >> complex);
	std::stringstream output;
	EXPECT_FALSE(output << complex);
	EXPECT_TRUE(output.str().empty());
}

TEST_F(TestComplex, TestInvalid5)
{
	EXPECT_FALSE(invalidInputs.at(5) >> complex);
	std::stringstream output;
	EXPECT_FALSE(output << complex);
	EXPECT_TRUE(output.str().empty());
}

TEST_F(TestComplex, TestInvalid6)
{
	EXPECT_FALSE(invalidInputs.at(6) >> complex);
	std::stringstream output;
	EXPECT_FALSE(output << complex);
	EXPECT_TRUE(output.str().empty());
}
