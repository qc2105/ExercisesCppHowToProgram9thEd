// Chapter5-exercises-5.31.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::cout << "Hello World!\n";

	double totalExpenses = 0.0;
	std::vector<std::string> expenseCategories({"housing", "food", "clothing", "transportation", "education", "health care", "vacations"});

	for (size_t i = 0; i < expenseCategories.size(); i++)
	{
		double expense = 0;
		std::cout << "Input " << expenseCategories.at(i) << " expenses\n";
		std::cin >> expense;
		totalExpenses += expense;
	}

	std::cout << "Your estimated FairTax: " << totalExpenses * 0.3 << std::endl;

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
