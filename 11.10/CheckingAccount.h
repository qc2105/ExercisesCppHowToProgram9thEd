#pragma once
#include "Account.h"
class CheckingAccount :
	public Account
{
public:
	CheckingAccount(const double InitBalance, const double FeePerTransAction);
	
	void credit(const double value);
	void debit(const double value);

	void setFeePerTransaction(const double fee);
	double getFeePerTransaction(void) const
	{
		return feePerTransaction;
	}

private:
	double feePerTransaction;
};

