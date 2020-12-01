// 7.9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <array>
#include <iomanip>

int main()
{
	std::array< std::array<int, 3>, 2> t;

	t = { 7,7,7,7,7,7 };
	for (auto &row : t)
	{
		for (auto &v : row)
			v += 3;
	}

	std::cout << "     [0] [1] [2]" << std::endl;
	for (int i = 0; i < 2; i++)
	{
		std::cout << "[" << i << "] ";
		for (int j = 0; j < 3; j++)
			std::cout << std::setw(3) << t[i][j] << ' ';
		std::cout << '\n';
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
