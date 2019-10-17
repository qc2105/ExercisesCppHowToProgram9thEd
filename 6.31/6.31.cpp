// 6.31.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

unsigned lcm(unsigned a, unsigned b)
{
	unsigned max = 0, min = 0;
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}

	for (unsigned int i = 1; i <= min; i++)
	{
		if (0 == ((max * i) % min))
		{
			return max * i;
		}
	}

	return a * b;
}

int main()
{
    std::cout << "Input two integers:\n";
	unsigned int a = 0, b = 0;
	std::cin >> a >> b;

	std::cout << lcm(a, b);

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
