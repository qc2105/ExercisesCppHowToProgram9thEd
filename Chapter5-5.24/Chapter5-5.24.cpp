// Chapter5-exercises-5.24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	std::cout << "Please input an odd number in range [1,19]\n";
	unsigned rows;
	
	while (true)
	{
		std::cin >> rows;
		if (rows % 2 != 1)
		{
			std::cout << "Please input an odd number in range [1,19]\n";
		}
		else
		{
			break;
		}
	}
	int k = (rows - 1) / 2;
	for (int i = 0; i < k + 1; i++)
	{
		for (int j = 0; j < k - i; j++)
		{
			std::cout << " ";
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << " ";
		}
		for (int j = 0; j < 2 * (k - i) + 1; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
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
