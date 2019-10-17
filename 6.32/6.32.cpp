// 6.32.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

std::string generateDivision(unsigned average)
{
	if (average > 100)
	{
		return std::string("invalid");
	}
	else if (average >= 60)
	{
		return std::string("First");
	}
	else if (average >= 45)
	{
		return std::string("Second");
	}
	else if (average >= 35)
	{
		return std::string("Third");
	}
	else
	{
		return std::string("Fail");
	}
}

int main()
{
    std::cout << "Input the student's average:\n";
	unsigned average = 0;
	std::cin >> average;
	std::cout << generateDivision(average);

	return 0;
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
