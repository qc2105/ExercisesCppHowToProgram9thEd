// 6.14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>

int roundToInteger(double number)
{
	return static_cast<int>(::floor(number + 0.5));
}

double roundToTenths(double number)
{
	return ::floor(number * 10 + 0.5) / 10.0;
}

double roundToHundredths(double number)
{
	return ::floor(number * 100 + 0.5) / 100.0;
}

double roundToThousandths(double number)
{
	return ::floor(number * 1000 + 0.5) / 1000.0;
}

int main()
{
    std::cout << "Please input a numberr, 0 to quit!\n"; 
	double number = 1.0;
	std::cout << std::left;
	size_t len = std::string("nearest thousandth").length() + 5;
	std::cout << std::setw(len) << "original value" << std::setw(len) << "nearest integer"
		<< std::setw(len) << "nearest tenth" << std::setw(len) << "nearest hundredth" << std::setw(len) << "nearest thousandth" << std::endl;
	for (; fabs(number - 0.0) > 0.0001; )
	{
		std::cin >> number;
		std::cout << std::setw(len) << number << std::setw(len) << roundToInteger(number)
			<< std::setw(len) << roundToTenths(number) << std::setw(len) << roundToHundredths(number)
			<< std::setw(len) << roundToThousandths(number) << std::endl;
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
