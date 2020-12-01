// Chapter4-execises-5.14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
	int productNumber;
	double quantitySold;
	double totalRetailValue = 0;
	do {
		std::cout << "Please input the product number: ";
		std::cin >> productNumber;
		if (productNumber < 0)
		{
			break;
		}
		else if (productNumber < 1 || productNumber > 5)
		{
			std::cout << "You have inputted a wroing number. The range is [1,5] whole number." << std::endl;
			continue;
		}
		std::cout << "Please input the quantity sold: ";
		std::cin >> quantitySold;
		switch (productNumber)
		{
		case 1:
			totalRetailValue += quantitySold * 2.98;
			break;
		case 2:
			totalRetailValue += quantitySold * 4.50;
			break;
		case 3:
			totalRetailValue += quantitySold * 9.98;
			break;
		case 4:
			totalRetailValue += quantitySold * 4.49;
			break;
		case 5:
			totalRetailValue += quantitySold * 6.87;
			break;
		default:
			break;
		}
	} while (productNumber > 0);

	std::cout << "Total retail value is: " << totalRetailValue << std::endl;
	
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
