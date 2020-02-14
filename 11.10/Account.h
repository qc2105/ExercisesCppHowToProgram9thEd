#pragma once
class Account
{
public:
	Account(const double Balance);

	bool setBalance(const double Balance);
	void credit(const double value);
	void debit(const double value);
	double getBalance(void) const;

private:
	double balance;
};

