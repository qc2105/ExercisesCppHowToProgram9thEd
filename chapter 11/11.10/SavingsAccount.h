#pragma once
#include "Account.h"
class SavingsAccount :
	public Account
{
public:
	SavingsAccount(const double initBalance, const double InterestRate);

	double getInterestRate(void) const
	{
		return interestRate;
	}
	void setInterestRate(const double rate);

	double calculateInterest(void) const;
private:
	double interestRate;
};

