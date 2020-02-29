// 14.7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

void createMaster(void);
void createTransaction(void);

int main()
{
	enum FILE_TYPE { MASTER = 1, TRANSACTION};

	int choice;

	std::cout << "Please input your choice: \n";
	std::cout << "1 for master file\n";
	std::cout << "2 for transaction file\n";

	std::cin >> choice;

	if (choice == MASTER)
	{
		std::cout << "You have chosen to create the master file\n";
		createMaster();
	}
	else if (choice == TRANSACTION)
	{
		std::cout << "You have chosen to create the transaction file\n";
		createTransaction();
	}
	else
	{
		std::cout << "Invalid choice, the app will exit\n";
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

void createMaster(void)
{
	std::cout << "Type CTR + Z to exit\n";
	std::ofstream outMaster("oldMaster.dat", std::ios::out);
	int accountNumber; std::string Lastname, FirstName; double currentBalance;
	while (std::cin >> accountNumber >> Lastname >> FirstName >> currentBalance)
	{
		outMaster << accountNumber << ' ' << Lastname << ' ' << FirstName << ' ' << currentBalance << std::endl;
	}
}

void createTransaction(void)
{
	std::cout << "Type CTR + Z to exit\n";
	std::ofstream outTransaction("transaction.dat", std::ios::out);
	int accountNumber; double dollarAmount;
	while (std::cin >> accountNumber >> dollarAmount)
	{
		outTransaction << accountNumber << ' ' << dollarAmount << std::endl;
	}
}
