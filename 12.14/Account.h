#pragma once
class Account
{
public:
	Account(const double Balance);
	virtual ~Account() {};

	bool setBalance(const double Balance);
	virtual void credit(const double value);
	virtual void debit(const double value);
	double getBalance(void) const;

private:
	double balance;
};

