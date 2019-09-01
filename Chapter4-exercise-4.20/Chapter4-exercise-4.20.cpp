// Chapter4-exercise-4.20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	unsigned passes = 0;
	unsigned failures = 0;
	unsigned studentCounter = 1;

	while (studentCounter <= 10)
	{
		int result = 0;
		
		while (true)
		{
			std::cout << "Enter result (1 = pass, 2 = faile): ";
			std::cin >> result;
			if (1 == result)
			{
				passes++;
				break;
			}
			else if (2 == result)
			{
				failures++;
				break;
			}
		}
		
		studentCounter++;
	}

	std::cout << "Passed " << passes << "\nFailed " << failures << std::endl;

	if (passes > 8)
	{
		std::cout << "Bonus to instructor!" << std::endl;
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
