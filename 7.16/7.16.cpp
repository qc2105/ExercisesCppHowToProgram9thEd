// 7.16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	
	std::array <long, 11> sumFrequency = { 0 };

	for (long i = 0; i < 36000; i++)
	{
		int die1 = rand() % 6 + 1;
		int die2 = rand() % 6 + 1;
		sumFrequency[die1 + die2 - 2] += 1;
	}

	for (int i = 2; i < 13; i++)
	{
		std::cout << std::setw(6) << i;
	}
	std::cout << std::endl;
	for (int i = 0; i < 11; i++)
	{
		std::cout << std::setw(6) << sumFrequency[i];
	}
	std::cout << std::endl;

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
