// 7.13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <array>

int main()
{
	const int totalLimit = 20;
	std::array<int, totalLimit> numbers = { 0 };
	int uniqueCount = 0;
	const int topNumber = 10;
	const int bottomNumber = 100;
	int inputNumber = -1;

	try {
		for (int i = 0; i < totalLimit; i++)
		{
			bool isUnique = true;
			std::cout << "Input the number, which is in range [10, 100]:" << std::endl;
			while (true)
			{
				std::cin >> inputNumber;
				if (inputNumber >= 10 && inputNumber <= 100)
				{
					break;
				}
				else
				{
					std::cout << "Only accept numbers in [10, 100]\n";
				}
			}
			if (uniqueCount != 0)
			{
				for (int i = 0; i < uniqueCount; i++)
				{
					if (numbers.at(i) == inputNumber)
					{
						isUnique = false;
					}
				}
			}
			
			if (isUnique)
			{
				numbers.at(uniqueCount) = inputNumber;
				uniqueCount++;
			}
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
			
	for (int i = 0; i < uniqueCount; i++)
	{
		std::cout << numbers.at(i) << ' ';
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
