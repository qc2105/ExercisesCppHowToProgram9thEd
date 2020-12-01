// 11.9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OvernightPackage.h"
#include "TwoDayPackage.h"

int main()
{
    std::cout << "Hello World!\n";

	double weight(100);
	double costPerOunce(100);
	double flatFee(99);
	double feePerOunce(100);
	Person sender("G", "Honey Road No.1", "HG", "HB", "242424");
	Person recipient("C", "Scientist Roat No.1", "WH", "HB", "666666");
	Package pack(sender, recipient, weight, costPerOunce);
	TwoDayPackage twoDayPack(sender, recipient, weight, costPerOunce, flatFee);
	OvernightPackage overnightPackage(sender, recipient, weight, costPerOunce, feePerOunce);

	std::cout << "Package cost: " << pack.calculateCost() << std::endl;
	std::cout << "TwoDayPackage cost: " << twoDayPack.calculateCost() << std::endl;
	std::cout << "OvernightPackage cost: " << overnightPackage.calculateCost() << std::endl;

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
