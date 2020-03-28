#pragma once
#include "Account.h"

namespace name12_14 {

	class CheckingAccount :
		public Account
	{
	public:
		CheckingAccount(const double InitBalance, const double FeePerTransAction);
		virtual ~CheckingAccount() {};

		virtual void credit(const double value);
		virtual void debit(const double value);

		void setFeePerTransaction(const double fee);
		double getFeePerTransaction(void) const
		{
			return feePerTransaction;
		}

	private:
		double feePerTransaction;
	};

}
