// Chapter4-exercises-4.27.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

int main()
{
    std::cout << "Hello World!\n"; 

	unsigned long long number = 0;
	unsigned long long devided = 0;
	int digit = -1;
	unsigned i = 0;
	std::vector<unsigned long long> digits;

	while (true)
	{
		if (number <= ULLONG_MAX / 2)
		{
			break;
		}
		else
		{
			std::cout << "Your input number must be less or equal than: " << ULLONG_MAX / 2 << std::endl;
		}
	}
	std::cout << "Input a binary number: ";
	std::cin >> number;

	while (true)
	{
		devided = number / (static_cast<unsigned long long>(pow(10, i)));
		if (devided < 10)
		{
			digits.push_back(devided);
			break;
		}
		digit = devided % 10;
		digits.push_back(digit);
		i++;
	}

	unsigned long long decimal = 0;
	unsigned j = 0;
	while (j < digits.size())
	{
		decimal += digits[j] * static_cast<unsigned long long>(pow(2, j));
		j++;
	}

	std::cout << "The equivalent decimal is: " << decimal << std::endl;

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
