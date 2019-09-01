#pragma once
class Account
{
public:
	Account();
	explicit Account(const int balance);
	~Account();

	int credit(const int amount);
	int debit(const int amount);
	int getBalance() const;
	int setBalance(const int amount);
	void displayBalance();

private:
	int balance;
};

