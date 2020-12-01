// Chapter-exercises-6.12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <vector>

double calculateCharges(double hours)
{
	if (hours <= 3)
	{
		return 2.0;
	}
	else
	{
		double charge = 0.0;
		charge = 2.0 + 0.5 * (hours - 3);
		if (charge > 10.0)
		{
			charge = 10.0;
		}

		return charge;
	}
}

double sum(std::vector<double> &vec)
{
	double sum = 0.0;
	for (size_t i = 0; i < vec.size(); i++)
	{
		sum += vec.at(i);
	}

	return sum;
}

int main()
{
	std::vector<double> hours;
	std::vector<double> charges;
	double hour = 0.0, charge = 0.0;

	while (hour >= 0.0)
	{
		std::cout << "Please input the hour for the customer, negative to stop the app.\n";
		std::cin >> hour;
		charge = calculateCharges(hour);
		if (hour > 0.0)
		{
			hours.push_back(hour);
			charges.push_back(charge);
		}
	}

	std::cout << std::fixed;
	std::cout << std::setw(5) << std::left << "Car" << std::setw(9) << std::right << "Hours" << std::setw(10) << "Charge" << std::endl;
	for (size_t i = 1; i < hours.size() + 1; i++)
	{
		std::cout << std::setw(5) << std::left << i << std::setw(9) << std::right << std::setprecision(1) << hours.at(i-1) << std::setw(10) << std::setprecision(2) << charges.at(i-1) << std::endl;
	}

	std::cout << std::setw(5) << std::left << "TOTAL" << std::setw(9) << std::right << std::setprecision(1) << sum(hours) << std::setw(10) << std::setprecision(2) << sum(charges) << std::endl;

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
