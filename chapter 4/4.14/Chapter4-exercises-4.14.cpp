// Chapter4-exercises-4.14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Hello World!\n"; 

	int accountNumber = 0;
	double beginningBalance = 0;
	double totalCharges = 0;
	double totalCredits = 0;
	double creditLimit = 0;
	double newBalance = 0;

	std::cout << std::setprecision(2) << std::fixed;
	while (true)
	{
		std::cout << "Enter account number (or -1 to quit): ";
		std::cin >> accountNumber;

		if (accountNumber == -1)
		{
			return 0;
		}

		std::cout << "Enter beginning balance: ";
		std::cin >> beginningBalance;
		std::cout << "Enter total charges: ";
		std::cin >> totalCharges;
		std::cout << "Enter total credits: ";
		std::cin >> totalCredits;
		std::cout << "Enter credit limit: ";
		std::cin >> creditLimit;

		newBalance = beginningBalance + totalCharges - totalCredits;
		std::cout << "New balance is " << newBalance << std::endl;

		if (newBalance > creditLimit)
		{
			std::cout << "Account: " << accountNumber << std::endl
				<< "Credit limit: " << creditLimit << std::endl
				<< "Balance: " << newBalance << std::endl
				<< "Credit Limit Exceeded." << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << std::endl;
		}
		
	}

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
