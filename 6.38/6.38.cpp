// 6.38.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

void move(int count, int start, int end, int temp)
{
	if (count > 0)
	{
		move(count - 1, start, temp, end);
		std::cout << "Move disk " << count << " from " << start << " to " << end << std::endl;
		move(count - 1, temp, end, start);
	}
}

int main()
{
    std::cout << "Hello World!\n"; 
	move(3, 1, 3, 2);
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
