// Chapter5-exercises-5.18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <assert.h>

void printDecimalToOthers(int decimal, int base)
{
	assert(decimal > 0);
	assert(base > 0);
	int mark = 1;

	for (unsigned i = 0; mark <= decimal; i++)
	{
		mark = static_cast<int>(pow(base, i));
	}

	mark /= base;

	while (mark >= 1)
	{
		if (decimal >= mark)
		{ 
			int digit = decimal / mark;
			if (digit < 10)
			{
				std::cout << digit;
			}
			else
			{
				switch (digit)
				{
				case 10:
					std::cout << 'A';
					break;
				case 11:
					std::cout << 'B';
					break;
				case 12:
					std::cout << 'C';
					break;
				case 13:
					std::cout << 'D';
					break;
				case 14:
					std::cout << 'E';
					break;
				case 15:
					std::cout << 'F';
					break;
				default:
					std::cout << '[' << digit << ']';
					break;
				}
			}
				
			decimal %= mark;
		}
		else
		{
			std::cout << 0;
		}

		mark /= base;
	}
}

int main()
{
    std::cout << "decimal\toctal\thexadecimal\n";
	for (int i = 1; i <= 256; i++)
	{
		std::cout << i << '\t';
		printDecimalToOthers(i, 8); std::cout << '\t';
		printDecimalToOthers(i, 16);
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
