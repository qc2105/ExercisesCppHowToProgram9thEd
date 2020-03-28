#pragma once
#include "Account.h"

namespace name12_14 {

	class SavingsAccount :
		public Account
	{
	public:
		SavingsAccount(const double initBalance, const double InterestRate);
		virtual ~SavingsAccount() {};

		double getInterestRate(void) const
		{
			return interestRate;
		}
		void setInterestRate(const double rate);

		double calculateInterest(void) const;
	private:
		double interestRate;
	};

}