#include "pch.h"
#include "../10.8/Complex.h"
#include <complex>

TEST(Test10_8, TestContor) 
{
	double real = 1.0;
	double imaginary = 2.3;
	Complex num(real, imaginary);
	
	EXPECT_EQ(num.getReal(), real);
	EXPECT_EQ(num.getImaginary(), imaginary);
}

TEST(Test10_8, TestSetter)
{
	double real = 1.1;
	double imaginary = 2.2;
	Complex num;
	num.setReal(real);
	num.setImaginary(imaginary);

	EXPECT_EQ(num.getReal(), real);
	EXPECT_EQ(num.getImaginary(), imaginary);
}

TEST(Test10_8, TestMultiply)
{
	double a = 3.2, b = 5.2, c = 2.6, d = 8.9;
	std::complex<double> stdCom(a, b), stdCom2(c, d);
	Complex com(a, b), com2(c, d);

	std::complex<double> expectedResult = stdCom * stdCom2;
	Complex realResult = com * com2;
	
	EXPECT_EQ(expectedResult.real(), realResult.getReal());
	EXPECT_EQ(expectedResult.imag(), realResult.getImaginary());
}

TEST(Test10_8, TestRelation)
{
	double real = 1.0, imaginary = 2.3;
	Complex num1(real, imaginary), num2(real, imaginary);

	EXPECT_TRUE(num1 == num2);
	EXPECT_FALSE(num1 != num2);

	double real2 = 1.1, imaginary2 = 2.4;
	Complex num3(real2, imaginary2);
	EXPECT_FALSE(num1 == num3);
	EXPECT_TRUE(num3 != num2);
}