// 14.6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

typedef struct masterRecord {
	int accountNumber;
	std::string firstName;
	std::string lastName;
	double currentBalance;
} mRecord;

typedef struct transactionRecord {
	int accountNumber;
	double dollarAmount;
} tRecord;

bool mCompare(const mRecord &a, const mRecord &b);
bool tCompare(const tRecord &a, const tRecord &b);

int main()
{
	std::ifstream inOldMaster("oldMaster.dat", std::ios::in);
	std::ifstream inTransaction("transaction.dat", std::ios::in);
	std::ofstream outNewMaster("newMaster.dat", std::ios::out);

	if (!inOldMaster || !inTransaction || !outNewMaster)
	{
		std::cout << "Files open operation failed\n";
		exit(EXIT_FAILURE);
	}

	std::vector<mRecord> masterRecordVec;
	std::vector<tRecord> transRecordVec;
	
	int accountNumber;
	std::string firstName;
	std::string lastName;
	double currentBalance, dollarAmount;

	while (inOldMaster >> accountNumber >> firstName >> lastName >> currentBalance)
	{
		mRecord newMR;
		newMR.accountNumber = accountNumber;
		newMR.firstName = firstName;
		newMR.lastName = lastName;
		newMR.currentBalance = currentBalance;
		masterRecordVec.push_back(newMR);
	}

	while (inTransaction >> accountNumber >> dollarAmount)
	{
		tRecord newTR;
		newTR.accountNumber = accountNumber;
		newTR.dollarAmount = dollarAmount;
		transRecordVec.push_back(newTR);
	}

	std::sort(masterRecordVec.begin(), masterRecordVec.end(), mCompare);
	std::sort(transRecordVec.begin(), transRecordVec.end(), tCompare);

	
	for (size_t j = 0; j < transRecordVec.size(); ++j)
	{
		bool eError = true;
		for (size_t i = 0; i < masterRecordVec.size(); ++i)
		{
			if (masterRecordVec.at(i).accountNumber == transRecordVec.at(j).accountNumber)
			{
				eError = false;
				masterRecordVec.at(i).currentBalance += transRecordVec.at(j).dollarAmount;
				break;
			}
		}
		if (eError)
		{
			std::cout << "Unmatched transaction record for account number: " << transRecordVec.at(j).accountNumber << '\n';
		}
	}
	
	for (size_t i = 0; i < masterRecordVec.size(); ++i)
	{
		outNewMaster << masterRecordVec.at(i).accountNumber << ' ' << masterRecordVec.at(i).firstName
			<< ' ' << masterRecordVec.at(i).lastName << ' ' << masterRecordVec.at(i).currentBalance << '\n';
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

bool mCompare(const mRecord & a, const mRecord & b)
{
	if (a.accountNumber < b.accountNumber)
		return true;
	else
		return false;
}

bool tCompare(const tRecord & a, const tRecord & b)
{
	if (a.accountNumber < b.accountNumber)
		return true;
	else
		return false;
}
