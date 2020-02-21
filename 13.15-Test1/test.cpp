#include "pch.h"
#include "../13.15/Point.h"
#include <sstream>
#include <string>

class PointInputTest : public ::testing::Test
{
protected:
	PointInputTest()
		:validInput1("(1,2)"),
		validInput2("(-1,-2)"),
		validInput3("0,3"),
		invalidInput1("1.5,2.5"),
		invalidInput2("(1, 2"),
		invalidInput3("(a,b)"),
		invalidInput4("(1:2)"),
		invalidInput5("(1,2"),
		emptyInput("")
	{

	}
	virtual ~PointInputTest()
	{

	}

	Point point;
	std::stringstream validInput1;
	std::stringstream validInput2;
	std::stringstream validInput3;
	std::stringstream invalidInput1;
	std::stringstream invalidInput2;
	std::stringstream invalidInput3;
	std::stringstream invalidInput4;
	std::stringstream invalidInput5;
	std::stringstream emptyInput;
};

TEST_F(PointInputTest, TestValidInput)
{
	EXPECT_TRUE(validInput1 >> point);
	EXPECT_TRUE(validInput2 >> point);
	EXPECT_TRUE(validInput3 >> point);
}

TEST_F(PointInputTest, TestValidOutput)
{
	validInput1 >> point;
	std::stringstream output1;
	EXPECT_TRUE(output1 << point);
	EXPECT_EQ(output1.str(), "(1,2)");

	validInput2 >> point;
	std::stringstream output2;
	EXPECT_TRUE(output2 << point);
	EXPECT_EQ(output2.str(), "(-1,-2)");

	validInput3 >> point;
	std::stringstream output3;
	EXPECT_TRUE(output3 << point);
	EXPECT_EQ(output3.str(), "(0,3)");
}

TEST_F(PointInputTest, TestInvalidFoat)
{
	EXPECT_FALSE(invalidInput1 >> point);
	std::stringstream output;
	EXPECT_FALSE(output << point);
	EXPECT_TRUE(output.str().empty());
}

TEST_F(PointInputTest, TestInvalidSpace)
{
	EXPECT_FALSE(invalidInput2 >> point);
	std::stringstream output;
	EXPECT_FALSE(output << point);
	EXPECT_TRUE(output.str().empty());
}

TEST_F(PointInputTest, TestInvalidAlpha)
{
	EXPECT_FALSE(invalidInput3 >> point);
	std::stringstream output;
	EXPECT_FALSE(output << point);
	EXPECT_TRUE(output.str().empty());
}

TEST_F(PointInputTest, TestInvalidNoComma)
{
	EXPECT_FALSE(invalidInput4 >> point);
	std::stringstream output;
	EXPECT_FALSE(output << point);
	EXPECT_TRUE(output.str().empty());
}

TEST_F(PointInputTest, TestInvalidMissingRightBrace)
{
	EXPECT_FALSE(invalidInput5 >> point);
	std::stringstream output;
	EXPECT_FALSE(output << point);
	EXPECT_TRUE(output.str().empty());
}

TEST_F(PointInputTest, TestInvalidEmptyInput)
{
	EXPECT_FALSE(emptyInput >> point);
	std::stringstream output;
	EXPECT_FALSE(output << point);
	EXPECT_TRUE(output.str().empty());
}
