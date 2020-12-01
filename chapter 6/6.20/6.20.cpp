// 6.20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

// Return true if the second is a factor of the first
bool is_a_factor(int first, int second)
{
	int temp;
	temp = first / second;
	
	return temp * second == first;
}

int main()
{
	int first, second;
	std::cout << "Input integer pairs:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> first >> second;

		if (is_a_factor(first, second))
		{
			std::cout << "Ture\n";
		}
		else
		{
			std::cout << "False\n";
		}
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
