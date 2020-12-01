// Chapter4-exercises-4.16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Hello World!\n"; 
	int hoursWorked = 0;
	double hourlyRate = 0;
	double overTimeRate = 1.5;
	double salary = 0;
	const int normalHours = 40;

	std::cout << std::setprecision(2) << std::fixed;
	while (true)
	{
		std::cout << "Enter hours worked (-1 to end): ";
		std::cin >> hoursWorked;
		if (-1 == hoursWorked)
		{
			return 0;
		}
		std::cout << "Enter hourly rate of the employee ($00.00): ";
		std::cin >> hourlyRate;

		if (hoursWorked > normalHours)
		{
			salary = normalHours * hourlyRate + (hoursWorked - normalHours) * hourlyRate * overTimeRate;
		}
		else
		{
			salary = hoursWorked * hourlyRate;
		}
		std::cout << "Salary is $" << salary << std::endl;
		std::cout << std::endl;
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
