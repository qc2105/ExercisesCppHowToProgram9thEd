// 6.19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>

double hypotenuse(double side1, double side2)
{
	return sqrt(side1 * side1 + side2 * side2);
}

int main()
{
    std::cout << std::fixed << std::setw(15) << "Triangle" << std::setw(15) << "Side 1" << std::setw(15) << "Side 2" << std::setw(15) << "Hypotenuse" << std::endl; 
	std::cout << std::setw(15) << "1" << std::setw(15) << "3.0" << std::setw(15) << "4.0" << std::setw(15) << hypotenuse(3.0, 4.0) << std::endl;
	std::cout << std::setw(15) << "2" << std::setw(15) << "5.0" << std::setw(15) << "12.0" << std::setw(15) << hypotenuse(5.0, 12.0) << std::endl;
	std::cout << std::setw(15) << "3" << std::setw(15) << "8.0" << std::setw(15) << "15.0" << std::setw(15) << hypotenuse(8.0, 15.0) << std::endl;
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
