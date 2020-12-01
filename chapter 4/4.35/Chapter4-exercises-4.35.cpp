// Chapter4-exercises-4.35.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

class Account
{
public:
	Account(unsigned accountNumber, std::string firstName, std::string lastName, double balance);
	void display();

private:
	unsigned m_accountNumber;
	std::string m_firstName;
	std::string m_lastName;
	double m_balance;
};

Account::Account(unsigned accountNumber, std::string firstName, std::string lastName, double balance):
	m_accountNumber(accountNumber),
	m_firstName(firstName),
	m_lastName(lastName),
	m_balance(balance)
{

}

void Account::display()
{
	std::cout << std::fixed;
	std::cout << m_accountNumber << " " << m_firstName << " " << m_lastName << ", " << m_balance << std::endl;
}


int main()
{
    std::cout << "Hello World!\n"; 
	unsigned studentCounter = { 10 };
	double initialBalance = { 1000.0 };
	Account myAccount = { 666, "Bruce", "Lee", 9999999999.9 };

	std::cout << studentCounter << "\t" << initialBalance << std::endl;

	myAccount.display();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
