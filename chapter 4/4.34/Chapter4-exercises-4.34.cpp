// Chapter4-exercises-4.34.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>

unsigned long long factorial(unsigned long long n)
{
	if (0 == n || 1 == n)
	{
		return 1;
	}
	unsigned long long i = 0;
	unsigned long long result = 1;
	while (i < n)
	{
		result *= (n - i);
		i++;
	}

	return result;
}

double value_of_e_power_x(double x, unsigned number_of_terms)
{
	unsigned i = 1;
	double value_of_e = 1;
	if (1 == number_of_terms)
	{
		std::cout << "e_power_x is: " << 1 << std::endl;
	}
	else if (2 == number_of_terms)
	{
		std::cout << "e_power_x is: " << 1 + x / static_cast<double>(1) << std::endl;
	}
	else
	{
		
		while (i < number_of_terms)
		{
			value_of_e += static_cast<double>(1) * pow(x, i) / static_cast<double>(factorial(i));
			i++;
		}
		std::cout << "e_power_x is: " << value_of_e << std::endl;
	}

	return value_of_e;
}

int main()
{
    std::cout << "Hello World!\n";
	unsigned long long inputNum = 0;
	std::cout << "Input a non-negative integer: ";
	std::cin >> inputNum;
	std::cout << inputNum << "'s factorial is " << factorial(inputNum) << std::endl;

	unsigned number_of_term;
	std::cout << "Input the number of terms you want: ";
	std::cin >> number_of_term;

	if (1 == number_of_term)
	{
		std::cout << "e is: " << 1 << std::endl;
	}
	else if (2 == number_of_term)
	{
		std::cout << "e is: " << 2 << std::endl;
	}
	else
	{
		unsigned i = 1;
		long double value_of_e = 1;
		while (i < number_of_term)
		{
			value_of_e += static_cast<long double>(1) / static_cast<long double>(factorial(i));
			i++;
		}
		std::cout << "e is: " << value_of_e << std::endl;
	}

	std::cout << "input x: ";
	double x;
	std::cin >> x;
	std::cout << "input number of terms: ";
	unsigned number_of_terms;
	std::cin >> number_of_terms;
	std::cout << "e power x is: " << value_of_e_power_x(x, number_of_terms) << std::endl;

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
