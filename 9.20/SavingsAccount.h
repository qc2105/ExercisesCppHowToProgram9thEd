#pragma once
#include <iostream>

class SavingsAccount
{
public:
	explicit SavingsAccount(double _savingsBalance);

	static double annualInterestRate;
	double calculateMonthlyInterest(void);
	static void modifyInterestRate(double newRate);

	void print(void)
	{
		std::cout << savingsBalance << std::endl;
	}
private:
	double savingsBalance;
};


