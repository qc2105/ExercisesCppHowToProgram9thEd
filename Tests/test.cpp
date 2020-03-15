#include "pch.h"
#include "../15.23/palindrome.h"
#include "../9.27/InputProcessor.h"
#include "../10.10/Rational.h"
#include "../10.11/InputProcessor.h"

TEST(Test10_11, TestInputProcessor)
{
	std::vector<Term> terms;
	name10_11::InputProcessor inp("1.5,3;2.2,2;3.1,1;5.2,0;");
	inp.getTerms(terms);

	std::vector<Term> expectedTerms = { Term(1.5, 3), Term(2.2, 2), Term(3.1,1), Term(5.2, 0) };

	EXPECT_EQ(expectedTerms, terms);
}

TEST(Test10_11, TestPolynomialContor)
{
	std::vector<Term> inputTerms = { Term(1.5, 2), Term(2.2, 3), Term(3.1,1), Term(5.2, 0) };

	Polynomial poly(inputTerms);
	std::vector<Term> outputTerms;
	poly.getTerms(outputTerms);

	std::vector<Term> expectedTerms = { Term(2.2, 3), Term(1.5, 2), Term(3.1,1), Term(5.2, 0) };

	EXPECT_EQ(expectedTerms, outputTerms);
}

TEST(Test10_11, TestAddition)
{
	std::vector<Term> terms1 = { Term(2.2, 3), Term(1.5, 2), Term(3.1,1), Term(5.2, 0) };
	std::vector<Term> terms2 = { Term(3.2, 5), Term(1.5, 2), Term(3.1,1), Term(5.2, 0) };

	Polynomial poly1(terms1), poly2(terms2);

	std::vector<Term> terms3 = { Term(3.2, 5), Term(2.2, 3), Term(3, 2), Term(6.2, 1), Term(10.4, 0) };

	Polynomial poly3(terms3);
	Polynomial poly4 = poly1 + poly2;

	EXPECT_EQ(poly3, poly4);

	std::vector<Term> terms2_2 = { Term(3.2, 5), Term(1.5, 2), Term(3.1,1) };
	Polynomial poly5(terms2_2);

	std::vector<Term> terms4 = { Term(3.2, 5), Term(2.2, 3), Term(3, 2), Term(6.2, 1), Term(5.2, 0) };
	Polynomial poly6(terms4);
	Polynomial poly7 = poly1 + poly5;

	EXPECT_EQ(poly7, poly6);
}

TEST(Test10_11, TestMinus)
{
	std::vector<Term> terms1 = { Term(2.2, 3), Term(1.5, 2), Term(3.1,1), Term(5.2, 0) };
	std::vector<Term> terms2 = { Term(3.2, 5), Term(1.5, 2), Term(3.1,1), Term(5.2, 0) };

	Polynomial poly1(terms1), poly2(terms2);

	std::vector<Term> terms3 = { Term(-3.2, 5), Term(2.2, 3) };

	Polynomial poly3(terms3);
	Polynomial poly4 = poly1 - poly2;

	EXPECT_EQ(poly3, poly4);

	std::vector<Term> terms2_2 = { Term(3.2, 5), Term(1.5, 2), Term(3.1,1) };
	Polynomial poly5(terms2_2);

	std::vector<Term> terms4 = { Term(-3.2, 5), Term(2.2, 3), Term(5.2, 0) };
	Polynomial poly6(terms4);
	Polynomial poly7 = poly1 - poly5;

	EXPECT_EQ(poly6, poly7);
}

TEST(Test10_11, TestReduceTerms)
{
	std::vector<Term> terms1 = { Term(2.2, 3), Term(1.5, 2), Term(3.6, 2), Term(0, 1), Term(5.2, 0) };
	std::vector<Term> expectTerms = { Term(2.2, 3), Term(5.1, 2), Term(5.2, 0) };

	Polynomial poly(terms1);

	std::vector<Term> reducedTerms;
	poly.getTerms(reducedTerms);

	EXPECT_EQ(expectTerms, reducedTerms);
}

TEST(Test10_11, TestAssignment)
{
	std::vector<Term> terms1 = { Term(2.2, 3), Term(5.1, 2), Term(5.2, 0) };

	Polynomial poly(terms1);

	Polynomial poly2 = poly;

	std::vector<Term> outputTerms;
	poly2.getTerms(outputTerms);

	EXPECT_EQ(terms1, outputTerms);

	poly = poly;
	outputTerms.clear();
	poly.getTerms(outputTerms);
	EXPECT_EQ(terms1, outputTerms);

	std::vector<Term> terms2 = { Term(9.9, 9) };
	Polynomial poly3(terms2);

	Polynomial poly4;
	poly4 = poly = poly3;

	EXPECT_EQ(poly4, poly3);
}

TEST(Test10_11, Test2PoliesMultiply)
{
	std::vector<Term> terms1 = { Term(2, 3), Term(5, 2), Term(5, 0) };
	std::vector<Term> terms2 = { Term(2, 2), Term(3, 1) };

	Polynomial poly1(terms1), poly2(terms2);

	std::vector<Term> expectedTerms = { Term(4, 5), Term(16, 4), Term(15, 3), Term(10, 2), Term(15, 1) };

	Polynomial poly3 = poly1 * poly2;
	Polynomial poly4(expectedTerms);

	EXPECT_EQ(poly3, poly4);

	Polynomial poly5 = poly2 * poly1;

	EXPECT_EQ(poly3, poly5);
}

TEST(Test10_11, Test2PoliesMultiplyAssign)
{
	std::vector<Term> terms1 = { Term(2, 3), Term(5, 2), Term(5, 0) };
	std::vector<Term> terms2 = { Term(2, 2), Term(3, 1) };

	Polynomial poly1(terms1), poly2(terms2);

	Polynomial poly3 = poly1 * poly2;

	poly2 *= poly1;

	EXPECT_EQ(poly3, poly2);
}

TEST(Test10_11, TestPolyMultiplyTerm)
{
	std::vector<Term> terms = { Term(2, 3), Term(5, 2), Term(5, 0) };
	Term term(2, 2);

	Polynomial poly1(terms);

	std::vector<Term> expectedTerms = { Term(4, 5), Term(10, 4), Term(10, 2) };
	Polynomial poly2(expectedTerms);

	Polynomial poly3 = poly1 * term;

	EXPECT_EQ(poly3, poly2);
}

TEST(Test10_10, TestContor)
{
	int num1 = 8, num2 = -4;
	Rational r(num1, num2);

	EXPECT_EQ(num1 / num2, r.getNumerator());
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

TEST(TestPalindrome, validPalindrome) {
    
    std::vector<int> intVec1 = { 1, 2, 3, 3, 2, 1 };
    std::vector<int> intVec2 = { 1, 2, 3, 2, 1 };
    
    EXPECT_TRUE(palindrome(intVec1));
    EXPECT_TRUE(palindrome(intVec2));
}

TEST(TestPalindrome, invalidPalindrome) {

    std::vector<int> intVec1 = { 1, 2, 3, 4, 2, 1 };
    std::vector<int> intVec2 = { 1, 2, 3, 6, 1 };

    EXPECT_FALSE(palindrome(intVec1));
    EXPECT_FALSE(palindrome(intVec2));
}

TEST(TestInputProcessor, TestGetInts)
{
	name9_27::InputProcessor ip("1,2;2,3;5,1;");
    std::vector<std::vector<size_t> > expectedInts = { {1,2}, {2,3}, {5,1} };

    std::vector<std::vector<size_t> > realInts;
    ip.getInts(realInts);

    EXPECT_EQ(expectedInts, realInts);
}