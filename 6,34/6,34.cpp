// 6,34.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(static_cast<unsigned>(time(0)));

	unsigned guessNumber = 0, realNumber = -1;

label:
	std::cout << "I have a number between 1 and 1000\n";
	std::cout << "Can you guess my number\n?"
		<< "Please type your first guess.";
	realNumber = rand() % 1000 + 1;

	while (true)
	{
		std::cin >> guessNumber;
		if (guessNumber == realNumber)
		{
			std::cout << "1. Excellent! You guessed the number!\n";
			std::cout << "Would you like to play again (y or n)?\n";
			char c = 'o';
			while (c != 'y' && c != 'n')
			{
				std::cin >> c;
			}
			if (c == 'y')
			{
				goto label;
			}
			else
			{
				break;
			}
		}
		else if (guessNumber < realNumber)
		{
			std::cout << "2. Too low. Try again.\n";
		}
		else
		{
			std::cout << "3. Too high. Try again.\n";
		}
	}
	
	
    std::cout << "Hello World!\n"; 
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
