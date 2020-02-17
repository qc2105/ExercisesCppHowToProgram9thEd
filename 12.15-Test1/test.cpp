#include "pch.h"
#include "../12.15/PieceWorker.h"
#include "../12.15/Employee.h"
#include "../12.15/HourlyWorker.h"

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
	catch (const std::exception & e)
	{
		std::string realExceptStr = e.what();
		EXPECT_EQ(expectExceptStr, realExceptStr);

		try
		{
			pw.setWagePerPiece(invalidWage2);
		}
		catch (const std::exception & e)
		{
			std::string realExceptStr = e.what();
			EXPECT_EQ(expectExceptStr, realExceptStr);
		}

		return;
	}

	// shouldn't reach here
	FAIL();
}

TEST_F(TestPieceWorker, TestSetNPiecesValid)
{
	double expectNPieces = 101;
	pw.setNPieces(expectNPieces);
	EXPECT_EQ(expectNPieces, pw.getNPieces());
}

TEST_F(TestPieceWorker, TestSetNPiecesInvalid)
{
	double invalidNPieces1 = 0, invalidNPieces2 = -100;
	std::string expectExceptStr = "NPieces must be positive\n";

	try
	{
		pw.setNPieces(invalidNPieces1);
	}
	catch (const std::exception & e)
	{
		std::string realExceptStr = e.what();
		EXPECT_EQ(expectExceptStr, realExceptStr);

		try
		{
			pw.setNPieces(invalidNPieces2);
		}
		catch (const std::exception & e)
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
	Employee *pEmpolyee = nullptr;
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
	catch (const std::exception &e)
	{
		std::string realExceptStr = e.what();
		EXPECT_EQ(expectExceptStr, realExceptStr);

		try
		{
			hwoker.setWagePerHour(invalidWage2);
		}
		catch (const std::exception &e)
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
	catch (const std::exception &e)
	{
		std::string realExceptStr = e.what();
		EXPECT_EQ(expectExceptStr, realExceptStr);

		try
		{
			hwoker.setNHours(invalidHours2);
		}
		catch (const std::exception &e)
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
	Employee *pEmployee = nullptr;
	pEmployee = &hwoker;
	EXPECT_EQ(hwoker.earnings(), pEmployee->earnings());
}

TEST_F(TestHourlyWorker, TestOvertimePay)
{
	int totalHours = 50;
	hwoker.setNHours(totalHours);
	EXPECT_EQ(wagePerHour * HourlyWorker::WorkHours + (totalHours - HourlyWorker::WorkHours) * wagePerHour * 1.5, hwoker.earnings());
}