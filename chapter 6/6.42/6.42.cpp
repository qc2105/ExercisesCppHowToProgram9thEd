// 6.42.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>

typedef double _3dPoint[3];
#define X 0
#define Y 1
#define Z 2

double distance(_3dPoint x, _3dPoint y)
{
	return sqrt(pow(x[X] - y[X], 2) + pow(x[Y] - y[Y], 2) + pow(x[Z] - y[Z], 2));
}

int main()
{
	_3dPoint x = { 1,3,5 };
	_3dPoint y = { 2,7,9 };
    std::cout << "(" << x[X] << "," << x[Y] << "," << x[Z] <<")"
		<< " to "
		<< "(" << y[X] << "," << y[Y] << "," << y[Z] << "): " << distance(x, y) << '\n'; 

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
