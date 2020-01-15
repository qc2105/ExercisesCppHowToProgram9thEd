#include "SavingsAccount.h"

double SavingsAccount::annualInterestRate = 0.03;

SavingsAccount::SavingsAccount(double _savingsBalance)
	:savingsBalance(_savingsBalance)
{
}

double SavingsAccount::calculateMonthlyInterest(void)
{
	double interest = savingsBalance * annualInterestRate / 12.0;
	savingsBalance += interest;

	return interest;
}

void SavingsAccount::modifyInterestRate(double newRate)
{
	annualInterestRate = newRate;
}
