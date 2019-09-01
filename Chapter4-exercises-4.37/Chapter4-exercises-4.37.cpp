// Chapter4-exercises-4.37.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Hello World!\n"; 
	unsigned long long population2019 = 7700000000;
	double growthRate2019 = 0.0108;
	int flag = 1;

	for (int i = 0; i < 75; i++)
	{
		std::cout << "Year\t" << "Population\t" << "Number Increased" << std::endl;
		std::cout << 2020 + i << "\t" << population2019 * pow((1 + growthRate2019), i + 1) << "\t" << population2019 * (pow((1 + growthRate2019), i + 1) - 1);
		if (2 * population2019 <= population2019 * pow((1 + growthRate2019), i + 1) && flag == 1)
		{
			std::cout << "\tDoubled in this year";
			flag = 0;
		}
		std::cout<< std::endl;
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
