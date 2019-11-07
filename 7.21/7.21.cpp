// 7.21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>

typedef struct slip {
	int salespersonNumber;
	int productNumber;
	double totalDollar;
} Slip;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	
	std::vector<Slip> data;

	for (int i = 0; i < 30; i++)
	{
		int salesPerson = rand() % 4 + 1;
		int productNumber = rand() % 5 + 1;
		double dollar = rand() % 10000 + 100;
		
		Slip datum;
		datum.productNumber = productNumber;
		datum.salespersonNumber = salesPerson;
		datum.totalDollar = dollar;

		data.push_back(datum);
	}

	std::array<std::array<double, 4>, 5> account = { 0 };
	for (auto v : data)
	{
		account[v.productNumber-1][v.salespersonNumber-1] = v.totalDollar;
	}

	std::cout << std::setw(10) << "        ";
	for (int i = 0; i < 4; i++)
	{
		std::cout << std::setw(9) << "Sales" << i + 1;
	}
	std::cout << "\n";
	int p = 1;
	for (auto product : account)
	{
		std::cout << std::setw(9) << "Product" << p++;
		for (auto sales : product)
		{
			std::cout << std::setw(10) << std::fixed << std::setprecision(2) << sales;
		}
		std::cout << "\n";
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
