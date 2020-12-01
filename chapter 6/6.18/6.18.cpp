// 6.18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>

bool integerPower(int base, unsigned exponent, int &result)
{
	result = 1;
	for (unsigned i = 0; i < exponent; i++)
	{
		if (result == -1 && base == INT_MIN)
			return false;					// Overflow
		if (base == -1 && result == INT_MIN)
			return false;					// Underflow
		if (result > INT_MAX / base)
			return false;					// Overflow 
		if (result < INT_MIN / base)
			return false;					// Underflow
		result *= base;
	}

	return true;
}

int main()
{
    std::cout << "Hello World!\n"; 

	int result;
	bool correct = true;
	for (int i = 1; i < 1000; i++)
	{
		if (!integerPower(i, 3, result))
		{
			std::cout << "Underflow or Overflow: " << i << std::endl;
		}

		if (result == static_cast<int>(pow(i, 3)))
		{
			std::cout << "Passed\n";
		}
		else
		{
			std::cout << "Failed\n";
			correct = false;
		}
	}

	std::cout << "------------------" << std::endl;
	std::cout << (correct ? "Passed" : "Failed") << std::endl;

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
