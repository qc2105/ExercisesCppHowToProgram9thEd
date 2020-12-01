// Chapter4-exercise-4.25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 

	unsigned int size = 0;
	std::cout << "Input size: ";
	while (true)
	{
		std::cin >> size;
		if (size >= 1 && size <= 20)
		{
			break;
		}
		else
		{
			std::cout << "must be in the range [1, 20], input again.";
		}
	}
	unsigned int i = 0;
	while (i < size)
	{
		if (0 == i || size - 1 == i)
		{
			unsigned int j = 0;
			while (j < size)
			{
				std::cout << "*";
				j++;
			}
			std::cout << std::endl;
		}
		else
		{
			unsigned int j = 0;
			while (j < size)
			{
				if (0 == j || size - 1 == j)
				{
					std::cout << "*";
				}
				else
				{
					std::cout << " ";
				}
				j++;
			}
			std::cout << std::endl;
		}
		i++;
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
