// Chapter4-exercises-4.32.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

bool is_triangle(double a, double b, double c)
{
	if (a + b > c && a + c > b && b + c > a)
	{
		return true;
	}

	return false;
}

int main()
{
    std::cout << "Hello World!\n"; 
	
	std::cout << "input side a: ";
	double side_a;
	std::cin >> side_a;
	
	std::cout << "input side b: ";
	double side_b;
	std::cin >> side_b;
	
	std::cout << "input side c: ";
	double side_c;
	std::cin >> side_c;

	if (is_triangle(side_a, side_b, side_c))
	{
		std::cout << "It's a triangle" << std::endl;
	}
	else
	{
		std::cout << "It's not a triangle" << std::endl;
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
