// 6.28.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

bool isPerfect(size_t integer)
{
	std::vector<size_t> divisors;
	size_t sum = 0;
	for (size_t i = 1; i < integer; i++)
	{
		if (0 == integer % i)
		{
			sum += i;
			divisors.push_back(i);
		}
	}

	if (sum == integer)
	{
		std::cout << integer << " = ";
		for (size_t i = 0; i < divisors.size() - 1; i++)
		{
			std::cout << divisors.at(i) << " + ";
		}

		std::cout << divisors.at(divisors.size() - 1) << std::endl;

		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	for (size_t i = 1; i <= 1000000; i++)
	{
		isPerfect(i);
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
