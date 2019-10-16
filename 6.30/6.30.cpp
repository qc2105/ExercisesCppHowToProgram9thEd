// 6.30.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>

void getDigits(unsigned integer, std::vector<char> &digits)
{
	if (0 == integer)
	{
		digits.push_back(0);
		return;
	}
	bool flag = false;
	int temp = 0;
	for (int i = 10000; i >= 1; i /= 10)
	{
		if (flag)
		{
			digits.push_back(integer / i);
			integer = integer % i;
		}
		else
		{
			if (integer / i != 0)
			{
				flag = true;
				digits.push_back(integer / i);
				integer = integer % i;
			}
		}
	}
}

int main()
{
	int integer = 0;
	unsigned target = 0;
	long long result = 0;
	bool negative = false;

	std::cout << "Input the integer: \n";
	std::cin >> integer;

	std::vector<char> digits;

	if (integer < 0)
	{
		target = -integer;
		negative = true;
	}
	else 
	{
		target = integer;
	}

	getDigits(target, digits);

	for (size_t i = 0; i < digits.size(); i++)
	{
		result += digits.at(i) * pow(10, i);
	}

	if (negative)
	{
		result = -result;
	}

	std::cout << result << std::endl;
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
