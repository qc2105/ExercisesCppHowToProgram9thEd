#include "CheckingAccount.h"
#include <stdexcept>

CheckingAccount::CheckingAccount(const double InitBalance, const double FeePerTransAction)
	:Account(InitBalance)
{
	setFeePerTransaction(FeePerTransAction);
}

void CheckingAccount::credit(const double value)
{
	if (value + Account::getBalance() >= getFeePerTransaction())
	{
		Account::credit(value);
		Account::debit(getFeePerTransaction());
		return;
	}
	throw std::invalid_argument("Not enough balance to pay the transaction fee\n");
}

void CheckingAccount::debit(const double value)
{
	if (value + getFeePerTransaction() <= Account::getBalance())
	{
		Account::debit(value);
		Account::debit(getFeePerTransaction());
		return;
	}
	throw std::invalid_argument("Not enough banlance to debit\n");
}

void CheckingAccount::setFeePerTransaction(const double fee)
{
	if (fee > 0)
	{
		feePerTransaction = fee;
		return;
	}
	throw std::invalid_argument("Fee must be positive\n");
}
