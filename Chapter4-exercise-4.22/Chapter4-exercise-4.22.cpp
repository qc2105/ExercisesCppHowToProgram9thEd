// Chapter4-exercise-4.22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 
	unsigned row = 10;
	
	while (row >= 1)
	{
		unsigned column = 1;
		while (column <= 10)
		{
			std::cout << (row % 2 ? "<" : ">");
			++column;
		}

		--row;
		std::cout << std::endl;
	}

	int x, y;
	
	x = 9, y = 11;
	if (x < 10)
		if (y > 10)
			std::cout << "*****" << std::endl;
		else
			std::cout << "#####" << std::endl;
	std::cout << "$$$$$" << std::endl;
	std::cout << "------------" << std::endl;
	if (x < 10)
	{
		if (y > 10)
			std::cout << "*****" << std::endl;
	}
	else
	{
		std::cout << "#####" << std::endl;
		std::cout << "$$$$$" << std::endl;
	}

	std::cout << "!!!!!!!!!!!!!!!!!!!" << std::endl;

	x = 11, y = 9;
	if (x < 10)
		if (y > 10)
			std::cout << "*****" << std::endl;
		else
			std::cout << "#####" << std::endl;
	std::cout << "$$$$$" << std::endl;
	std::cout << "------------" << std::endl;
	if (x < 10)
	{
		if (y > 10)
			std::cout << "*****" << std::endl;
	}
	else
	{
		std::cout << "#####" << std::endl;
		std::cout << "$$$$$" << std::endl;
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
