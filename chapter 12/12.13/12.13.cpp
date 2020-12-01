// 12.13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OvernightPackage.h"
#include "TwoDayPackage.h"
#include <vector>

int main()
{
    std::cout << "Hello World!\n";
	double totalCost = 0;

	std::vector<name12_13::Package*> pPacks(3, nullptr);

	name12_13::Person Sender("Chuan Qin", "Some Place No.1", "San Diego", "CA", "92121");
	name12_13::Person Recipient("Chuan Qin", "Some Place No.2", "Wuhan", "Hubei", "439000");
	double Weight(100);
	double CostPerOunce(100);
	double FlatFee(100);
	name12_13::TwoDayPackage tdp(Sender, Recipient, Weight, CostPerOunce, FlatFee);
	name12_13::OvernightPackage onp(Sender, Recipient, Weight, CostPerOunce, CostPerOunce * 2);
	name12_13::Package pak(Sender, Recipient, Weight, CostPerOunce);

	pPacks.at(0) = &pak;
	pPacks.at(1) = &onp;
	pPacks.at(2) = &tdp;

	for (size_t i = 0; i < pPacks.size(); ++i)
	{
		pPacks.at(i)->printInfo();
		totalCost += pPacks.at(i)->calculateCost();
		std::cout << typeid(*pPacks.at(i)).name() << ", cost: " << pPacks.at(i)->calculateCost() << "\n-------------------\n";
		pPacks.at(i) = nullptr;
	}

	std::cout << "TotalCost: " << totalCost << "\n";

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
