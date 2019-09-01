#include "stdafx.h"
#include "Account.h"

#include <iostream>
using namespace std;

Account::Account()
{
}

Account::Account(const int _balance)
{
	setBalance(_balance);
}


Account::~Account()
{
}

int Account::credit(const int amount)
{
	if (amount > 0)
	{ 
		int current_balance = getBalance();
		setBalance(current_balance + amount);
		return 0;
	}
	else
	{
		cerr << "Invalid input, amount should be greater then 0. Balance is left unchanged" << endl;
		return -1;
	}
}

int Account::debit(const int amount)
{
	int current_balance = getBalance();
	if (current_balance - amount >= 0)
	{
		setBalance(current_balance - amount);
		return 0;
	}
	else
	{
		cerr << "Invalid input, debit amount exceeded account balance. Balance is left unchanged" << endl;
		return -1;
	}
}

int Account::getBalance() const
{	
	return balance;
}

int Account::setBalance(const int amount)
{
	if (amount >= 0)
	{
		balance = amount;
		return 0;
	}
	else
	{
		balance = 0;
		cerr << "invalid input, amount should be greater or equal to 0. It has been set to 0 instead." << endl;
		return -1;
	}
}

void Account::displayBalance()
{
	std::cout << getBalance() << endl;
}
