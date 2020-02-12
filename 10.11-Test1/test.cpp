#include "pch.h"
#include "../10.11/InputProcessor.h"

TEST(Test10_11, TestInputProcessor) 
{
	std::vector<Term> terms;
	InputProcessor inp("1.5,3;2.2,2;3.1,1;5.2,0;");
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
	std::vector<Term> expectTerms = { Term(2.2, 3), Term (5.1, 2), Term(5.2, 0)};

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
}

TEST(Test10_11, Test2PoliesMultiply)
{
	std::vector<Term> terms1 = { Term(2, 3), Term(5, 2), Term(5, 0) };
	std::vector<Term> terms2 = { Term(2, 2), Term(3, 1)};

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

	std::vector<Term> expectedTerms = { Term(4, 5), Term(10, 4), Term(10, 2)};
	Polynomial poly2(expectedTerms);

	Polynomial poly3 = poly1 * term;

	EXPECT_EQ(poly3, poly2);
}


