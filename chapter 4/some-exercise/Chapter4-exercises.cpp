// Chapter4-exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Hello World!\n";
	double miles = 0;
	double gallons = 0;
	double milesSum = 0;
	double gallonsSum = 0;

	std::cout << "Enter miles driven (-1 to quit): ";
	std::cin >> miles;
	while (abs(miles - (-1)) > 0.000001)
	{
		std::cout << "Enter gallons used: ";
		std::cin >> gallons;

		milesSum += miles;
		gallonsSum += gallons;

		std::cout << std::setprecision(6) << std::fixed;
		std::cout << "MPG this trip: " << miles / gallons << std::endl;
		std::cout << "Total MPG: " << milesSum / gallonsSum << std::endl;

		std::cout << "Enter miles driven (-1 to quit): ";
		std::cin >> miles;
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
