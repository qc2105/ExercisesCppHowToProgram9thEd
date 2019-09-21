// Chapter5-exercises-5.32.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "Hello World!\n"; 
	std::vector<double> rates({0.02, 0.03, 0.04, 0.05});

	for (size_t i = 0; i < rates.size(); i++)
	{
		size_t n;
		for (n = 0; pow((1 + rates[i]), n) < 2.5; n++)
		{

		}
		std::cout << "Rate: " << rates[i] << " for " << n << " months\n";
	}
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
