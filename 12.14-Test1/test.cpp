#include "pch.h"
#include "../12.14/CheckingAccount.h"
#include "../12.14/SavingsAccount.h"

class TestPolymorphism : public ::testing::Test
{
protected:
	TestPolymorphism()
		:initBalance(10000),
		interestRate(.02),
		feePerTrans(10),
		valueCredit(100),
		valueDebit(80),
		cant(initBalance, feePerTrans),
		sant(initBalance, interestRate),
		pAccount(nullptr)
	{
	};

	virtual ~TestPolymorphism() {};

	double initBalance;
	double interestRate;
	double feePerTrans;
	double valueCredit;
	double valueDebit;
	CheckingAccount cant;
	SavingsAccount sant;
	Account *pAccount;
};

TEST_F(TestPolymorphism, TestCheckingAccount)
{
	pAccount = &cant;
	pAccount->credit(valueCredit);
	double expBalance(initBalance + valueCredit - feePerTrans);
	EXPECT_EQ(expBalance, pAccount->getBalance());
	
	pAccount->debit(valueDebit);
	EXPECT_EQ(expBalance - valueDebit - feePerTrans, pAccount->getBalance());
}

TEST_F(TestPolymorphism, TestSavingsAccount)
{
	pAccount = &sant;
	pAccount->credit(valueCredit);
	double expBalance(initBalance + valueCredit);
	EXPECT_EQ(expBalance, pAccount->getBalance());

	pAccount->debit(valueDebit);
	EXPECT_EQ(expBalance - valueDebit, pAccount->getBalance());
}