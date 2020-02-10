#include "pch.h"
#include "../10.10/Rational.h"

TEST(Test10_10, TestContor) 
{
	int num1 = 8, num2 = -4;
	Rational r(num1, num2);

	EXPECT_EQ(num1/num2, r.getNumerator());
	EXPECT_EQ(1, r.getDenominator());

	Rational r2(num2, num1);
	EXPECT_EQ(-1, r2.getNumerator());
	EXPECT_EQ(2, r2.getDenominator());
}

TEST(Test10_10, TestEqual)
{
	int num1 = 1, num2 = 2, num3 = 4;
	
	Rational r1(num1, num2), r2(num2, num3);
	EXPECT_TRUE(r1 == r2);

	Rational r3(num1, num3);
	EXPECT_FALSE(r1 == r3);
}

TEST(Test10_10, TestAddition)
{
	int num1 = -1, num2 = 2, num3 = 3, num4 = 4;
	Rational r1(num1, num2), r2(num3, num4);

	EXPECT_TRUE(Rational(1, 4) == r1 + r2);
}

TEST(Test10_10, TestSubtraction)
{
	int num1 = -1, num2 = 2, num3 = 3, num4 = 4;
	Rational r1(num1, num2), r2(num3, num4);

	EXPECT_TRUE(r2 - r1 == Rational(5, 4));
}

TEST(Test10_10, TestMultiplay)
{
	int num1 = -1, num2 = 2, num3 = 3, num4 = 4;
	Rational r1(num1, num2), r2(num3, num4);

	EXPECT_TRUE(r1 * r2 == Rational(-3, 8));
}

TEST(Test10_10, TestDivide)
{
	int num1 = -1, num2 = 2, num3 = 3, num4 = 4;
	Rational r1(num1, num2), r2(num3, num4);

	EXPECT_TRUE(r2 / r1 == Rational(-3, 2));
}

TEST(Test10_10, TestBiggerThan)
{
	int num1 = -1, num2 = 2, num3 = 3, num4 = 4;
	Rational r1(num1, num2), r2(num3, num4);

	EXPECT_TRUE(r2 > r1);
	EXPECT_FALSE(r1 > r2);
}

TEST(Test10_10, TestBiggerThanOrEqual)
{
	int num1 = -1, num2 = 2, num3 = 3, num4 = 4;
	Rational r1(num1, num2), r2(num3, num4);

	EXPECT_TRUE(r2 >= r1);
	EXPECT_FALSE(r1 >= r2);
	EXPECT_TRUE(r1 >= r1);
}

TEST(Test10_10, TestLessThan)
{
	int num1 = -1, num2 = 2, num3 = 3, num4 = 4;
	Rational r1(num1, num2), r2(num3, num4);

	EXPECT_TRUE(r1 < r2);
	EXPECT_FALSE(r2 < r1);
}