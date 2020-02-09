#include "pch.h"
#include "../10.9/Hugeint.h"

TEST(Test10_9, TestBigger) 
{
	int bigger = 8, smaller = 6;
	HugeInt bigInt(bigger), smallInt(smaller);
	EXPECT_TRUE(bigInt > smallInt);
	EXPECT_FALSE(smallInt > bigInt);
}

TEST(Test10_9, TestMultiply)
{
	int num1 = 12, num2 = 13;
	std::string numStr3("111111111111"), numStr4("2");

	HugeInt num3 = HugeInt(num1) * HugeInt(num2);
	EXPECT_EQ(num3, HugeInt(12 * 13));

	HugeInt num4 = HugeInt(numStr3) * HugeInt(numStr4);
	EXPECT_EQ(num4, HugeInt(std::string("222222222222")));

	EXPECT_EQ(HugeInt(num1) * num2, HugeInt(num1) * HugeInt(num2));
	EXPECT_EQ(HugeInt(numStr3) * HugeInt(numStr4), HugeInt(numStr3) * numStr4);
}

TEST(Test10_9, TestEqual)
{
	int num1 = 33, num2 = 44;
	EXPECT_TRUE(HugeInt(num1) == HugeInt(num1));
	EXPECT_FALSE(HugeInt(num1) == HugeInt(num2));
	EXPECT_FALSE(HugeInt(num1) != HugeInt(num1));
	EXPECT_TRUE(HugeInt(num1) != HugeInt(num2));
}

TEST(Test10_9, TestLess)
{
	int num1 = 33, num2 = 44;
	HugeInt int1(num1), int2(num2);

	EXPECT_TRUE(int1 < int2);
	EXPECT_FALSE(int1 >= int2);
}

TEST(Test10_9, TestDivide)
{
	int num1 = 11, num2 = 22, num3 = 55;
	HugeInt int1(num1), int2(num2), int3(num3);

	EXPECT_EQ(int3 / int1, num3 / num1);
	EXPECT_EQ(int3 / int2, num3 / num2);
	EXPECT_EQ(int1 / int2, num1 / num2);
	EXPECT_EQ(int1 / int1, num1 / num1);
	EXPECT_EQ(int3 / num1, num3 / num1);
	
	std::string numStr1("2");
	HugeInt int4(numStr1);
	EXPECT_EQ(int2 / int4, int2 / numStr1);
}