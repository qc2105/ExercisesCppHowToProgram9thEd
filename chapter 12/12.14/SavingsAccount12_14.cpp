#include "SavingsAccount.h"
#include <stdexcept>

namespace name12_14 {

	SavingsAccount::SavingsAccount(const double initBalance, const double InterestRate)
		:Account(initBalance)
	{
		setInterestRate(InterestRate);
	}

	void SavingsAccount::setInterestRate(const double rate)
	{
		if (rate > 0)
		{
			interestRate = rate;
			return;
		}

		throw std::invalid_argument("Interest rate must be positive.\n");
	}

	double SavingsAccount::calculateInterest(void) const
	{
		return Account::getBalance() * getInterestRate();
	}

}