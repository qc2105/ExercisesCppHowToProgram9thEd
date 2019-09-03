// Chapter4-execercises-5.12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 
	int stars[4][10];
	int blanks[4][10];

	for (int i = 0; i < 10; i++)
	{
		stars[0][i] = i + 1;
		stars[1][i] = 10 - i;
		stars[2][i] = stars[1][i];
		stars[3][i] = stars[0][i];
	}

	for (int i = 0; i < 10; i++)
	{
		blanks[0][i] = 9 - i;
		blanks[1][i] = i;
		blanks[2][i] = i;
		blanks[3][i] = blanks[0][i];
	}

	
	for (int i = 0; i < 10; i++)
	{
		for (int h = 0; h < 2; h++)
		{
			for (int j = 0; j < stars[h][i]; j++)
			{
				std::cout << "*";
			}
			for (int j = 0; j < blanks[h][i]; j++)
			{
				std::cout << " ";
			}
			for (int b = 0; b < 6; b++)
			{
				std::cout << " ";
			}
		}
		for (int h = 2; h < 4; h++)
		{
			for (int j = 0; j < blanks[h][i]; j++)
			{
				std::cout << " ";
			}
			for (int j = 0; j < stars[h][i]; j++)
			{
				std::cout << "*";
			}
			for (int b = 0; b < 6; b++)
			{
				std::cout << " ";
			}
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
