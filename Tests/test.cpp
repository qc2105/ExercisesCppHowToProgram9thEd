#include "pch.h"
#include "../15.23/palindrome.h"
#include "../9.27/InputProcessor.h"
#include "../10.10/Rational.h"
#include "../10.11/InputProcessor.h"
#include "../10.8/Complex.h"
#include <complex>
#include "../10.9/Hugeint.h"
#include "../11.10/Account.h"
#include "../11.10/SavingsAccount.h"
#include "../11.10/CheckingAccount.h"
#include "../11.9/Package.h"
#include "../11.9/TwoDayPackage.h"
#include "../11.9/OvernightPackage.h"
#include "../15.24/prime.h"

#include "../13.16/Complex13_16.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "../12.15/PieceWorker.h"
#include "../12.15/Employee.h"
#include "../12.15/HourlyWorker.h"

#include "../14.10/Person.h"
#include <fstream>

#include "../13.15/Point.h"
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

class PersonTest : public ::testing::Test
{
protected:
	PersonTest()
		:ioPerson("persons.dat", std::ios::out | std::ios::binary),
		InvalidPerson1(-1, "Someguy", "forker", 11),
		InvalidPerson0(0, "Dummy", "Foo", 1),
		person1(1, "First", "Q", 9999),
		person22(22, "John", "Wick", 33),
		person99(99, "Peter", "Wong", 99),
		InvalidPerson100(100, "Jeff", "American", 100)
	{
	}
	virtual ~PersonTest()
	{

	}

	virtual void SetUp() override
	{
		name14_10::initialize(ioPerson);
		ioPerson.close();
		ioPerson.open("persons.dat", std::ios::in | std::ios::out | std::ios::binary);
		if (!ioPerson)
		{
			std::cerr << "Open file failed\n";
			FAIL();
		}
	}

	virtual void TearDown() override
	{
		ioPerson.close();
	}

	std::fstream ioPerson;
	name14_10::Person InvalidPerson1;
	name14_10::Person InvalidPerson0;
	name14_10::Person person1;
	name14_10::Person person22;
	name14_10::Person person99;
	name14_10::Person InvalidPerson100;
};

TEST_F(PersonTest, TestInitialize)
{
	ioPerson.seekg(0);
	if (!ioPerson)
	{
		std::cerr << "Seek error\n";
		FAIL();
	}

	for (size_t i = 0; i < name14_10::SIZELIMIT; ++i)
	{
		name14_10::Person temp(person99);
		ioPerson.read(reinterpret_cast<char*>(&temp), sizeof(name14_10::Person));
		if (!ioPerson)
		{
			std::cerr << "Read error\n";
			FAIL();
		}

		ASSERT_EQ(temp.getId(), 0);
		ASSERT_EQ(temp.getFirstName(), "");
		ASSERT_EQ(temp.getLastName(), "unassigned");
		ASSERT_EQ(temp.getAge(), 0);
	}
}

TEST_F(PersonTest, TestAddInvalidInput0)
{
	std::stringstream invalidInput0(std::to_string(InvalidPerson0.getId()) + ' ' + InvalidPerson0.getFirstName() + ' ' +
		InvalidPerson0.getLastName() + ' ' + std::to_string(InvalidPerson0.getAge()));
	ASSERT_FALSE(name14_10::add(ioPerson, invalidInput0));
}

TEST_F(PersonTest, TestAddInvalidInput1)
{
	std::stringstream invalidInput1(std::to_string(InvalidPerson1.getId()) + ' ' + InvalidPerson1.getFirstName() + ' ' +
		InvalidPerson1.getLastName() + ' ' + std::to_string(InvalidPerson1.getAge()));
	ASSERT_FALSE(name14_10::add(ioPerson, invalidInput1));
}

TEST_F(PersonTest, TestAddInvalidInput2)
{
	std::stringstream invalidInput100(std::to_string(InvalidPerson100.getId()) + ' ' + InvalidPerson100.getFirstName() + ' ' +
		InvalidPerson100.getLastName() + ' ' + std::to_string(InvalidPerson100.getAge()));
	ASSERT_FALSE(name14_10::add(ioPerson, invalidInput100));
}

TEST_F(PersonTest, TestAddValid0)
{
	std::stringstream validInput0(std::to_string(person1.getId()) + ' ' + person1.getFirstName() + ' ' +
		person1.getLastName() + ' ' + std::to_string(person1.getAge()));
	ASSERT_TRUE(name14_10::add(ioPerson, validInput0));

	ioPerson.flush();

	ioPerson.seekg((person1.getId() - 1) * sizeof(name14_10::Person));
	if (!ioPerson)
	{
		std::cerr << "Seek error\n";
		FAIL();
	}
	name14_10::Person temp;
	ioPerson.read(reinterpret_cast<char*>(&temp), sizeof(name14_10::Person));
	if (!ioPerson)
	{
		std::cerr << "Read error\n";
		FAIL();
	}

	ASSERT_EQ(temp.getId(), 1);
	ASSERT_EQ(temp.getFirstName(), "First");
	ASSERT_EQ(temp.getLastName(), "Q");
	ASSERT_EQ(temp.getAge(), 9999);
}

TEST_F(PersonTest, TestAddValid1)
{
	std::stringstream validInput0(std::to_string(person22.getId()) + ' ' + person22.getFirstName() + ' ' +
		person22.getLastName() + ' ' + std::to_string(person22.getAge()));
	ASSERT_TRUE(name14_10::add(ioPerson, validInput0));

	ioPerson.flush();

	ioPerson.seekg((person22.getId() - 1) * sizeof(name14_10::Person));
	if (!ioPerson)
	{
		std::cerr << "Seek error\n";
		FAIL();
	}
	name14_10::Person temp;
	ioPerson.read(reinterpret_cast<char*>(&temp), sizeof(name14_10::Person));
	if (!ioPerson)
	{
		std::cerr << "Read error\n";
		FAIL();
	}

	ASSERT_EQ(temp.getId(), 22);
	ASSERT_EQ(temp.getFirstName(), "John");
	ASSERT_EQ(temp.getLastName(), "Wick");
	ASSERT_EQ(temp.getAge(), 33);
}

TEST_F(PersonTest, TestAddValid2)
{
	std::stringstream validInput0(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	ASSERT_TRUE(name14_10::add(ioPerson, validInput0));

	ioPerson.flush();

	ioPerson.seekg((person99.getId() - 1) * sizeof(name14_10::Person));
	if (!ioPerson)
	{
		std::cerr << "Seek error\n";
		FAIL();
	}
	name14_10::Person temp;
	ioPerson.read(reinterpret_cast<char*>(&temp), sizeof(name14_10::Person));
	if (!ioPerson)
	{
		std::cerr << "Read error\n";
		FAIL();
	}

	ASSERT_EQ(temp.getId(), 99);
	ASSERT_EQ(temp.getFirstName(), "Peter");
	ASSERT_EQ(temp.getLastName(), "Wong");
	ASSERT_EQ(temp.getAge(), 99);
}

TEST_F(PersonTest, TestUpdateValid1)
{
	std::stringstream validInput0(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	if (!name14_10::add(ioPerson, validInput0))
	{
		std::cerr << "Error adding\n";
		FAIL();
	}

	std::stringstream validInput1(std::to_string(person99.getId()) + ' ' + person22.getFirstName() + ' ' +
		person22.getLastName() + ' ' + std::to_string(person22.getAge()));
	ASSERT_TRUE(name14_10::update(ioPerson, validInput1));

	ioPerson.seekg((person99.getId() - 1) * sizeof(name14_10::Person));
	if (!ioPerson)
	{
		std::cerr << "Seek error\n";
		FAIL();
	}
	name14_10::Person temp;
	ioPerson.read(reinterpret_cast<char*>(&temp), sizeof(name14_10::Person));
	ASSERT_EQ(temp.getId(), 99);
	ASSERT_EQ(temp.getFirstName(), person22.getFirstName());
	ASSERT_EQ(temp.getLastName(), person22.getLastName());
	ASSERT_EQ(temp.getAge(), person22.getAge());
}

TEST_F(PersonTest, TestUpdateInvalid1)
{
	std::stringstream validInput0(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	if (!name14_10::add(ioPerson, validInput0))
	{
		std::cerr << "Error adding\n";
		FAIL();
	}

	std::stringstream validInput1(std::to_string(person22.getId()) + ' ' + person22.getFirstName() + ' ' +
		person22.getLastName() + ' ' + std::to_string(person22.getAge()));
	ASSERT_FALSE(name14_10::update(ioPerson, validInput1));
}

TEST_F(PersonTest, TestDelValid1)
{
	std::stringstream validInput0(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	if (!name14_10::add(ioPerson, validInput0))
	{
		std::cerr << "Error adding\n";
		FAIL();
	}

	std::stringstream validInput1(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	ASSERT_TRUE(name14_10::del(ioPerson, validInput1));
}

TEST_F(PersonTest, TestDelInvalid1)
{
	std::stringstream validInput0(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	if (!name14_10::add(ioPerson, validInput0))
	{
		std::cerr << "Error adding\n";
		FAIL();
	}

	std::stringstream validInput1(std::to_string(person22.getId()) + ' ' + person22.getFirstName() + ' ' +
		person22.getLastName() + ' ' + std::to_string(person22.getAge()));
	ASSERT_FALSE(name14_10::del(ioPerson, validInput1));
}

TEST_F(PersonTest, TestDelInvalid2)
{
	std::stringstream validInput0(std::to_string(person99.getId()) + ' ' + person99.getFirstName() + ' ' +
		person99.getLastName() + ' ' + std::to_string(person99.getAge()));
	if (!name14_10::add(ioPerson, validInput0))
	{
		std::cerr << "Error adding\n";
		FAIL();
	}

	std::stringstream invalidInput100(std::to_string(InvalidPerson100.getId()) + ' ' + InvalidPerson100.getFirstName() + ' ' +
		InvalidPerson100.getLastName() + ' ' + std::to_string(InvalidPerson100.getAge()));
	ASSERT_FALSE(name14_10::del(ioPerson, invalidInput100));
}

class TestPieceWorker : public ::testing::Test
{
protected:
	TestPieceWorker()
		:first("Chuan"),
		last("Qin"),
		ssn("111-1111-1111"),
		wagePerPiece(1000),
		nPieces(100),
		pw(first, last, ssn, wagePerPiece, nPieces)
	{

	};

	virtual ~TestPieceWorker() {};

	std::string first;
	std::string last;
	std::string ssn;
	double wagePerPiece;
	unsigned nPieces;
	PieceWorker pw;
};

TEST_F(TestPieceWorker, TestContor)
{
	EXPECT_EQ(nPieces, pw.getNPieces());
	EXPECT_EQ(wagePerPiece, pw.getWagePerPiece());
}

TEST_F(TestPieceWorker, TestSetWagePerPieceValid)
{
	double wageToBeSet = 1200;
	pw.setWagePerPiece(wageToBeSet);
	EXPECT_EQ(wageToBeSet, pw.getWagePerPiece());
}

TEST_F(TestPieceWorker, TestSetWagePerPieceInvalid)
{
	double invalidWage1 = 0, invalidWage2 = -100;
	std::string expectExceptStr = "WagePerPiece must be positive\n";

	try
	{
		pw.setWagePerPiece(invalidWage1);
	}
	catch (const std::exception& e)
	{
		std::string realExceptStr = e.what();
		EXPECT_EQ(expectExceptStr, realExceptStr);

		try
		{
			pw.setWagePerPiece(invalidWage2);
		}
		catch (const std::exception& e)
		{
			std::string realExceptStr = e.what();
			EXPECT_EQ(expectExceptStr, realExceptStr);
			return;
		}
	}

	// shouldn't reach here
	FAIL();
}

TEST_F(TestPieceWorker, TestSetNPiecesValid)
{
	long expectNPieces = 101;
	pw.setNPieces(expectNPieces);
	EXPECT_EQ(expectNPieces, pw.getNPieces());
}

TEST_F(TestPieceWorker, TestSetNPiecesInvalid)
{
	long invalidNPieces1 = 0, invalidNPieces2 = -100;
	std::string expectExceptStr = "NPieces must be positive\n";

	try
	{
		pw.setNPieces(invalidNPieces1);
	}
	catch (const std::exception& e)
	{
		std::string realExceptStr = e.what();
		EXPECT_EQ(expectExceptStr, realExceptStr);

		try
		{
			pw.setNPieces(invalidNPieces2);
		}
		catch (const std::exception& e)
		{
			std::string realExceptStr = e.what();
			EXPECT_EQ(expectExceptStr, realExceptStr);
			return;
		}
	}

	// Shouldn't reach here.
	FAIL();
}

TEST_F(TestPieceWorker, TestEarnings)
{
	EXPECT_EQ(wagePerPiece * nPieces, pw.earnings());
}

TEST_F(TestPieceWorker, TestPolymorphism)
{
	Employee* pEmpolyee = nullptr;
	pEmpolyee = &pw;
	EXPECT_EQ(pw.earnings(), pEmpolyee->earnings());
}


class TestHourlyWorker : public ::testing::Test
{
protected:
	TestHourlyWorker()
		:first("Chuan"),
		last("Qin"),
		ssn("111-1111-1111"),
		wagePerHour(100),
		nHours(30),
		hwoker(first, last, ssn, wagePerHour, nHours)
	{

	};

	virtual ~TestHourlyWorker() {};

	std::string first;
	std::string last;
	std::string ssn;
	double wagePerHour;
	unsigned nHours;
	HourlyWorker hwoker;
};


TEST_F(TestHourlyWorker, TestContor)
{
	EXPECT_EQ(wagePerHour, hwoker.getWagePerHour());
	EXPECT_EQ(nHours, hwoker.getNHours());
}

TEST_F(TestHourlyWorker, TestSetWagePerHourInvalid)
{
	double invalidWage1 = 0, invalidWage2 = -100;
	std::string expectExceptStr = "Wage must be positive\n";

	try
	{
		hwoker.setWagePerHour(invalidWage1);
	}
	catch (const std::exception& e)
	{
		std::string realExceptStr = e.what();
		EXPECT_EQ(expectExceptStr, realExceptStr);

		try
		{
			hwoker.setWagePerHour(invalidWage2);
		}
		catch (const std::exception& e)
		{
			std::string realExceptStr = e.what();
			EXPECT_EQ(expectExceptStr, realExceptStr);
			return;
		}
	}

	// shouldn't reach here;
	FAIL();
}

TEST_F(TestHourlyWorker, TestSetNHoursInvalid)
{
	unsigned invalidHours1 = 0;
	int invalidHours2 = -100;
	std::string expectExceptStr = "Hours must be positive\n";

	try
	{
		hwoker.setNHours(invalidHours1);
	}
	catch (const std::exception& e)
	{
		std::string realExceptStr = e.what();
		EXPECT_EQ(expectExceptStr, realExceptStr);

		try
		{
			hwoker.setNHours(invalidHours2);
		}
		catch (const std::exception& e)
		{
			std::string realExceptStr = e.what();
			EXPECT_EQ(expectExceptStr, realExceptStr);
			return;
		}
	}

	// shouldn't reach here;
	FAIL();
}

TEST_F(TestHourlyWorker, TestEarnings)
{
	EXPECT_EQ(nHours * wagePerHour, hwoker.earnings());
}

TEST_F(TestHourlyWorker, TestPolymorphism)
{
	Employee* pEmployee = nullptr;
	pEmployee = &hwoker;
	EXPECT_EQ(hwoker.earnings(), pEmployee->earnings());
}

TEST_F(TestHourlyWorker, TestOvertimePay)
{
	int totalHours = 50;
	hwoker.setNHours(totalHours);
	EXPECT_EQ(wagePerHour * HourlyWorker::WorkHours + (totalHours - HourlyWorker::WorkHours) * wagePerHour * 1.5, hwoker.earnings());
}


class TestComplex : public ::testing::Test
{
protected:

	TestComplex()
	{
		char* validInputsArray[] = {
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

		char* invalidInputsArray[] = {
			"",
			"+",
			"-",
			"+3q",
			"-3t",
			"+-",
			"--",
			"5+"
		};

		for (size_t i = 0; i < sizeof(validInputsArray) / sizeof(char*); ++i)
		{
			validInputs.push_back(std::stringstream(validInputsArray[i]));
		}
		for (size_t i = 0; i < sizeof(invalidInputsArray) / sizeof(char*); ++i)
		{
			invalidInputs.push_back(std::stringstream(invalidInputsArray[i]));
		}
	}
	virtual ~TestComplex() {}

	name13_16::Complex complex;
	std::vector<std::stringstream> validInputs;
	std::vector<std::stringstream> invalidInputs;
};

TEST_F(TestComplex, TestEqual)
{
	name13_16::Complex c1(1, 2), c2(1, 2);
	EXPECT_EQ(c1, c2);
}

TEST_F(TestComplex, TestOutPut0)
{
	name13_16::Complex c0(3, 8);
	std::stringstream out;
	out << c0;
	EXPECT_EQ("3+8i", out.str());
}

TEST_F(TestComplex, TestOutPut1)
{
	name13_16::Complex c1(-3, -8);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("-3-8i", out.str());
}

TEST_F(TestComplex, TestOutPut2)
{
	name13_16::Complex c1(-3, 8);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("-3+8i", out.str());
}

TEST_F(TestComplex, TestOutPut3)
{
	name13_16::Complex c1(3, -8);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("3-8i", out.str());
}

TEST_F(TestComplex, TestOutPut4)
{
	name13_16::Complex c1(3, 0);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("3", out.str());
}

TEST_F(TestComplex, TestOutPut5)
{
	name13_16::Complex c1(0, 8);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("8i", out.str());
}

TEST_F(TestComplex, TestOutPut6)
{
	name13_16::Complex c1(-3, 0);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("-3", out.str());
}

TEST_F(TestComplex, TestOutPut7)
{
	name13_16::Complex c1(0, -8);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("-8i", out.str());
}

TEST_F(TestComplex, TestOutPut8)
{
	name13_16::Complex c1(0, 0);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("0", out.str());
}

TEST_F(TestComplex, TestOutPut9)
{
	name13_16::Complex c1(0, 1);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("i", out.str());
}

TEST_F(TestComplex, TestOutPut10)
{
	name13_16::Complex c1(5, 1);
	std::stringstream out;
	out << c1;
	EXPECT_EQ("5+i", out.str());
}

TEST_F(TestComplex, TestValidInput0)
{
	EXPECT_TRUE(validInputs.at(0) >> complex);
	name13_16::Complex c1(3, 8);
	EXPECT_EQ(c1, complex);
}

TEST_F(TestComplex, TestValidInput1)
{
	EXPECT_TRUE(validInputs.at(1) >> complex);
	name13_16::Complex c1(3, 8);
	EXPECT_EQ(c1, complex);
}

TEST_F(TestComplex, TestValidInput2)
{
	EXPECT_TRUE(validInputs.at(2) >> complex);
	name13_16::Complex c2(-3, -8);
	EXPECT_EQ(c2, complex);
}

TEST_F(TestComplex, TestValidInput3)
{
	EXPECT_TRUE(validInputs.at(3) >> complex);
	name13_16::Complex c3(-3, +8);
	EXPECT_EQ(c3, complex);
}

TEST_F(TestComplex, TestValidInput4)
{
	EXPECT_TRUE(validInputs.at(4) >> complex);
	name13_16::Complex c4(+3, -8);
	EXPECT_EQ(c4, complex);
}

TEST_F(TestComplex, TestValidInput5)
{
	EXPECT_TRUE(validInputs.at(5) >> complex);
	name13_16::Complex c4(+3, -8);
	EXPECT_EQ(c4, complex);
}

TEST_F(TestComplex, TestValidInput6)
{
	EXPECT_TRUE(validInputs.at(6) >> complex);
	name13_16::Complex c5(3, 0);
	EXPECT_EQ(c5, complex);
}

TEST_F(TestComplex, TestValidInput7)
{
	EXPECT_TRUE(validInputs.at(7) >> complex);
	name13_16::Complex c6(0, 8);
	EXPECT_EQ(c6, complex);
}

TEST_F(TestComplex, TestValidInput8)
{
	EXPECT_TRUE(validInputs.at(8) >> complex);
	name13_16::Complex c7(-3, 0);
	EXPECT_EQ(c7, complex);
}

TEST_F(TestComplex, TestValidInput9)
{
	EXPECT_TRUE(validInputs.at(9) >> complex);
	name13_16::Complex c8(0, -8);
	EXPECT_EQ(c8, complex);
}

TEST_F(TestComplex, TestValidInput10)
{
	EXPECT_TRUE(validInputs.at(10) >> complex);
	name13_16::Complex c8(0, 0);
	EXPECT_EQ(c8, complex);
}

TEST_F(TestComplex, TestValidInput11)
{
	EXPECT_TRUE(validInputs.at(11) >> complex);
	name13_16::Complex c8(0, 1);
	EXPECT_EQ(c8, complex);
}

TEST_F(TestComplex, TestValidInput12)
{
	EXPECT_TRUE(validInputs.at(12) >> complex);
	name13_16::Complex c8(5, 1);
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

TEST_F(TestComplex, TestInvalid7)
{
	EXPECT_FALSE(invalidInputs.at(7) >> complex);
	std::stringstream output;
	EXPECT_FALSE(output << complex);
	EXPECT_TRUE(output.str().empty());
}

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

class Test11_10 : public ::testing::Test
{
public:
	Test11_10()
		:initBalance(100000),
		account(initBalance),
		interestRate(0.01),
		savingsAccount(initBalance, interestRate),
		feePerTransaction(10),
		checkingAccount(initBalance, feePerTransaction)
	{

	}

	double initBalance;
	Account account;
	double interestRate;
	SavingsAccount savingsAccount;
	double feePerTransaction;
	CheckingAccount checkingAccount;
};

TEST_F(Test11_10, TestAccountContor)
{
	EXPECT_EQ(initBalance, account.getBalance());
}

TEST_F(Test11_10, TestAccountSetBalance)
{
	double invalidBalance = -100;
	bool ret = account.setBalance(invalidBalance);
	EXPECT_EQ(0, account.getBalance());
	EXPECT_EQ(false, ret);

	double validBalance = 100;
	ret = account.setBalance(validBalance);
	EXPECT_EQ(true, ret);
	EXPECT_EQ(validBalance, account.getBalance());
}

TEST_F(Test11_10, TestAccountCredit)
{
	double invalidValue1 = 0, invalidValue2 = -1;
	double validValue = 100;
	std::string exceptionStr = "Credit value should be positive.\n";

	try
	{
		account.credit(invalidValue1);
	}
	catch (const std::exception & e)
	{
		std::string realExcept = e.what();
		EXPECT_EQ(exceptionStr, realExcept);

		try
		{
			account.credit(invalidValue2);
		}
		catch (const std::exception & e)
		{
			std::string realExcept = e.what();
			EXPECT_EQ(exceptionStr, realExcept);

			account.credit(validValue);
			EXPECT_EQ(initBalance + validValue, account.getBalance());
			return;
		}
	}

	//shouldn't reach here.
	EXPECT_FALSE(true);
}

TEST_F(Test11_10, TestAccountDebit)
{
	double invalidValue = 100001;
	double validValue = 100;
	std::string exceptionStr = "Debit amount exceeded account balance\n";

	try
	{
		account.debit(invalidValue);
	}
	catch (const std::exception & e)
	{
		std::string realExcept = e.what();
		EXPECT_EQ(exceptionStr, realExcept);

		account.debit(validValue);
		EXPECT_EQ(initBalance - validValue, account.getBalance());
		return;
	}

	//shouldn't reach here.
	EXPECT_FALSE(true);
}

TEST_F(Test11_10, TestSavingsAccountContor)
{
	EXPECT_EQ(initBalance, savingsAccount.getBalance());
	EXPECT_EQ(interestRate, savingsAccount.getInterestRate());
}

TEST_F(Test11_10, TestSavingsAccountSetInterestRate)
{
	double invalidInterstRate = -0.1, validInterestRate = 0.02;
	std::string expectExceptionStr = "Interest rate must be positive.\n";

	try
	{
		savingsAccount.setInterestRate(invalidInterstRate);
	}
	catch (const std::exception & e)
	{
		std::string realExcept = e.what();
		EXPECT_EQ(expectExceptionStr, realExcept);

		savingsAccount.setInterestRate(validInterestRate);
		EXPECT_EQ(validInterestRate, savingsAccount.getInterestRate());
		return;
	}

	//shouldn't reach here
	EXPECT_FALSE(true);
}

TEST_F(Test11_10, TestSavingsAccountCalculateInterest)
{
	double expectedInterest = savingsAccount.getBalance() * savingsAccount.getInterestRate();
	EXPECT_EQ(expectedInterest, savingsAccount.calculateInterest());
}

TEST_F(Test11_10, TestCheckingAccountContor)
{
	EXPECT_EQ(initBalance, checkingAccount.getBalance());
	EXPECT_EQ(feePerTransaction, checkingAccount.getFeePerTransaction());
}

TEST_F(Test11_10, TestCheckingAccountSetFeePerTransaction)
{
	double invalidFee1 = 0, invalidFee2 = -10, validFee = 99;
	std::string expectedExceptStr = "Fee must be positive\n";

	try
	{
		checkingAccount.setFeePerTransaction(invalidFee1);
	}
	catch (std::exception & e)
	{
		std::string realExcept = e.what();
		EXPECT_EQ(expectedExceptStr, realExcept);

		try
		{

			checkingAccount.setFeePerTransaction(invalidFee2);
		}

		catch (std::exception & e)
		{
			std::string realExcept = e.what();
			EXPECT_EQ(expectedExceptStr, realExcept);

			checkingAccount.setFeePerTransaction(validFee);
			EXPECT_EQ(validFee, checkingAccount.getFeePerTransaction());
			return;
		}
	}

	//shouldn't reach here
	EXPECT_FALSE(true);
}

TEST_F(Test11_10, TestCheckingAccountCredit)
{
	double invalidValue1 = 0, invalidValue2 = -1;
	std::string expectedStr = "Credit value should be positive.\n";

	try
	{
		checkingAccount.credit(invalidValue1);
	}
	catch (const std::exception & e)
	{
		std::string realExcept = e.what();
		EXPECT_EQ(expectedStr, realExcept);

		try
		{
			checkingAccount.credit(invalidValue2);
		}
		catch (const std::exception & e)
		{
			std::string realExcept = e.what();
			EXPECT_EQ(expectedStr, realExcept);

			double newBalance = 0, invalidValue3 = feePerTransaction - 1;
			checkingAccount.setBalance(0);
			expectedStr = "Not enough balance to pay the transaction fee\n";
			try
			{
				checkingAccount.credit(invalidValue3);
			}
			catch (const std::exception & e)
			{
				std::string realExcept = e.what();
				EXPECT_EQ(expectedStr, realExcept);

				double validValue = feePerTransaction, expectBalance = 0;
				checkingAccount.credit(validValue);
				EXPECT_EQ(expectBalance, checkingAccount.getBalance());
				return;
			}
		}
	}

	//shouldn't reach here
	FAIL();
}

TEST_F(Test11_10, TestCheckingAccountDebit)
{
	double invalidValue1 = 0, invalidValue2 = -1;
	double invalidValue3 = checkingAccount.getBalance() - checkingAccount.getFeePerTransaction() + 1;
	std::string expectStr = "Debit amount must be positive\n";

	try
	{
		checkingAccount.debit(invalidValue1);
	}
	catch (const std::exception & e)
	{
		std::string realExcept = e.what();
		EXPECT_EQ(expectStr, realExcept);

		try
		{
			checkingAccount.debit(invalidValue2);
		}
		catch (const std::exception & e)
		{
			std::string realExcept = e.what();
			EXPECT_EQ(expectStr, realExcept);

			try
			{
				checkingAccount.debit(invalidValue3);
			}
			catch (const std::exception & e)
			{
				std::string realExcept = e.what();
				expectStr = "Not enough banlance to debit\n";
				EXPECT_EQ(expectStr, realExcept);

				double validValue = 520;
				checkingAccount.debit(validValue);
				EXPECT_EQ(initBalance - validValue - feePerTransaction, checkingAccount.getBalance());
				return;
			}
		}
	}

	//should'nt reach here
	FAIL();
}
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

TEST(Test15_25, TestGetPrimes)
{
	std::bitset<10000> bset;
	std::vector<size_t> primes;

	EXPECT_TRUE(getPrimes(666, bset));
	EXPECT_TRUE(getPrimes(666, primes));

	for (int i = 0; i < primes.size(); ++i)
	{
		EXPECT_TRUE(bset[primes.at(i)]);
	}
	size_t count = 0;
	for (int i = 0; i < 666; ++i)
	{
		if (bset[i])
		{
			++count;
		}
	}
	EXPECT_EQ(count, primes.size());
	
	std::bitset<10000> bset2;
	std::vector<size_t> primes2;
	EXPECT_TRUE(getPrimes(666, bset2, primes2));
	EXPECT_EQ(bset, bset2);
	EXPECT_EQ(primes, primes2);
}

TEST(Test15_26, TestGetUniquePrimesFactors)
{
	int inputNumber = 54;
	std::vector<size_t> expectFactors = { 2, 3, 3, 3 };
	std::vector<size_t> realFactors;
	
	EXPECT_TRUE(getUniquePrimesFactors(inputNumber, realFactors));

	EXPECT_EQ(expectFactors, realFactors);
}

TEST(Test15_25, TestGetPrimesFactors)
{
	int inputNumber = 54;
	std::set<size_t> expectFactors = { 2, 3};
	std::set<size_t> realFactors;

	EXPECT_TRUE(getPrimesFactors(inputNumber, realFactors));

	EXPECT_EQ(expectFactors, realFactors);
}