// Chapter5-exercises-5.9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <assert.h>

int main()
{
    std::cout << "Hello World!\n";

	unsigned product = 1;

	for (unsigned i = 2; i <= 15; i+=2)
	{
		product *= i;
	}

	unsigned check_product = 1;
	for (unsigned i = 1; i <= 15; i++)
	{
		if (0 == i % 2)
		{
			check_product *= i;
		}
	}

	assert(product == check_product);

	std::cout << "The product of even numbers between 1 and 15 is: " << product << std::endl;

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
