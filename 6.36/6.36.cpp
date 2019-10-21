// 6.36.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cassert>

double power(double base, unsigned exponent)
{
	assert(exponent >= 1);
	if (1 == exponent)
	{
		return base;
	}
	else
	{
		return base * power(base, exponent - 1);
	}
}

int main()
{
	unsigned exp;
	std::cout << "Input the exp (>= 1): \n";
	std::cin >> exp;
	for (int i = 1; i < 11; i++)
	{
		std::cout << "Power(" << i << ", " << exp << ") = " << power(i, exp) << std::endl;
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
