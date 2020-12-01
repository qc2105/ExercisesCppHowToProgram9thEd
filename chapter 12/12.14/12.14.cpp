// 12.14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

int main()
{
    std::cout << "Hello World!\n";
	std::vector<name12_14::Account * > pAccounts(2, nullptr);

	double initBalance(10000),
		interestRate(.02),
		feePerTrans(10),
		valueCredit(100),
		valueDebit(80);
	name12_14::CheckingAccount cant(initBalance, feePerTrans);
	name12_14::SavingsAccount sant(initBalance, interestRate);

	pAccounts.at(0) = &cant;
	pAccounts.at(1) = &sant;

	for (size_t i = 0; i < pAccounts.size(); ++i)
	{
		std::cout << typeid(*(pAccounts.at(i))).name() << " with a balance of: " << pAccounts.at(i)->getBalance() << std::endl;
		std::cout << "Input the money amount in dollars to withdraw: " << '\n';
		std::cin >> valueDebit;
		std::cout << "Input the money amount in dollars to deposit: " << '\n';
		std::cin >> valueCredit;
		pAccounts.at(i)->debit(valueDebit);
		pAccounts.at(i)->credit(valueCredit);

		name12_14::SavingsAccount *pSavingsAccount = nullptr;
		pSavingsAccount = dynamic_cast<name12_14::SavingsAccount *>(pAccounts.at(i));
		if (pSavingsAccount)
		{
			pAccounts.at(i)->credit(pSavingsAccount->calculateInterest());
		}

		std::cout << "The updated balance: " << pAccounts.at(i)->getBalance() << std::endl;

		pAccounts.at(i) = nullptr;
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
