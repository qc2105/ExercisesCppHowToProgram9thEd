#include "pch.h" 
#include "../11.10/Account.h"
#include "../11.10/SavingsAccount.h"
#include "../11.10/CheckingAccount.h"

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
	catch (const std::exception &e)
	{
		std::string realExcept = e.what();
		EXPECT_EQ(exceptionStr, realExcept);

		try
		{
			account.credit(invalidValue2);
		}
		catch (const std::exception &e)
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
	catch (const std::exception &e)
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
	catch (const std::exception &e)
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
	catch (std::exception &e)
	{
		std::string realExcept = e.what();
		EXPECT_EQ(expectedExceptStr, realExcept);

		try
		{

			checkingAccount.setFeePerTransaction(invalidFee2);
		}

		catch (std::exception &e)
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
	catch (const std::exception &e)
	{
		std::string realExcept = e.what();
		EXPECT_EQ(expectedStr, realExcept);

		try
		{
			checkingAccount.credit(invalidValue2);
		}
		catch (const std::exception &e)
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
			catch (const std::exception &e)
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
	catch (const std::exception &e)
	{
		std::string realExcept = e.what();
		EXPECT_EQ(expectStr, realExcept);

		try
		{
			checkingAccount.debit(invalidValue2);
		}
		catch (const std::exception &e)
		{
			std::string realExcept = e.what();
			EXPECT_EQ(expectStr, realExcept);

			try
			{
				checkingAccount.debit(invalidValue3);
			}
			catch (const std::exception &e)
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