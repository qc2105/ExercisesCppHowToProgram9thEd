// Chapter5-exercises-5.11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    std::cout << "Hello World!\n"; 
	double amount;
	double principal = 1000.0;
	double dRate = .05;

	std::cout << "Year" << std::setw(15) << std::right << "Amount" << std::endl;

	std::cout << std::fixed << std::setprecision(2);
	
	
		for (unsigned year = 1; year <= 10; ++year)
		{
			std::cout << std::setw(4) << year;
			for (unsigned rate = 11; rate <= 16; ++rate)
			{
				dRate = static_cast<double>(rate) / 100;
				amount = principal * pow(1.0 + dRate, year);
				std::cout << std::setw(15) << amount << ", at " << std::setw(3) << rate << "%";
			}
			std::cout << std::endl;
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
