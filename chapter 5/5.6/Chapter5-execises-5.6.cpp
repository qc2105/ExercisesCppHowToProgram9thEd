// Chapter5-execises-5.6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 
	double sum = 0;
	unsigned count = 0;
	const int sentinel = 9999;
	int intputInteger;
	
	std::cout << "Enter the integers. Enter 9999 to finish inputing." << std::endl;

	while (true)
	{
		std::cin >> intputInteger;
		if (sentinel == intputInteger)
		{
			break;
		}
		else
		{
			sum += intputInteger;
			count++;
		}
	}

	if (0 != count)
	{
		std::cout << "The average is: " << sum / count << std::endl;
	}
	else
	{
		std::cout << "No integer has been inputted. The average is assumed to be 0!\n";
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
