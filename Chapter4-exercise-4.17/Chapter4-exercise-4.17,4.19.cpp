// Chapter4-exercise-4.17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 

	int counter = 0;
	double number = 0;
	double largest = 0;
	double smallest = 0;

	while (counter < 10)
	{
		std::cout << "Input current number:";
		std::cin >> number;
		if (number > largest)
		{
			largest = number;
		}
		if (number < smallest)
		{
			smallest = number;
		}
		counter++;
	}
	std::cout <<
		"The largest number of 10 numbers input by the user is: "
		<< largest << std::endl;
	std::cout <<
		"The smallest number of 10 numbers input by the user is: "
		<< smallest << std::endl << std::endl;

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
