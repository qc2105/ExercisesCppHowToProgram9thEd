// Chapter5-exercises-5.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "Hello World!\n"; 

	int inputInteger = 1;
	int numberOfIntegers;
	double product = 1;
	unsigned largest;
	std::vector<int> integers;

	std::cout << "<number of integer to be input> <integer1> <integer2> ..." << std::endl;
	std::cin >> numberOfIntegers;

	for (int i = 0; i < numberOfIntegers; i++)
	{
		std::cin >> inputInteger;
		integers.push_back(inputInteger);
		product *= inputInteger;
	}

	std::cout << "The product: " << product << std::endl;

	if (integers.size() > 0)
	{
		largest = integers[0];

		for (unsigned i = 0; i < integers.size(); i++)
		{
			if (integers[i] > largest)
			{
				largest = integers[i];
			}
		}
	}

	std::cout << "The largest integer is: " << largest << std::endl;

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
