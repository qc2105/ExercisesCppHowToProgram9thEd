// Chapter4-exercises-4.26.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "Hello World!\n"; 

	unsigned fiveDigitInteger = 0;

	while (true)
	{
		std::cout << "Please input a five digit integer: " << std::endl;
		std::cin >> fiveDigitInteger;

		if ( fiveDigitInteger > 9999 && fiveDigitInteger < 99999)
		{
			break;
		}
		else
		{
			std::cout << "You must input a five digit positive integer." << std::endl;
		}
	}


	std::vector<int> digits(5);

	// store the digits in vector digits in original order.
	digits[0] = fiveDigitInteger / 10000;
	digits[1] = fiveDigitInteger / 1000 % 10;
	digits[2] = fiveDigitInteger / 100 % 10;
	digits[3] = fiveDigitInteger / 10 % 10;
	digits[4] = fiveDigitInteger % 10;
	
	// check whether digits[0] == digits[4] and digits[1] == digits[3]

	if (digits[0] == digits[4] && digits[1] == digits[3])
	{
		std::cout << "It's a palindrome." << std::endl;
	}
	else
	{
		std::cout << "It's not a palindrome." << std::endl;
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
