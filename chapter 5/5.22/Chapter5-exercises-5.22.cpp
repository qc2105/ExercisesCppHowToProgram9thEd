// Chapter5-exercises-5.22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <time.h>

int main()
{
    std::cout << "Hello World!\n";  
	int x, y, i, a, b, g, j = 0;
	for (i = 10; i < 300; i++)
	{
		srand(time(NULL));
		x = rand() % i;
		srand(time(NULL));
		y = rand() % i;
		srand(time(NULL));
		a = rand() % i;
		srand(time(NULL));
		b = rand() % i;
		srand(time(NULL));
		g = rand() % i;
		srand(time(NULL));
		j = rand() % i;
		std::cout << (!(x < 5) && !(y >= 7)) << !(x < 5 || y >= 7) << " | ";
		std::cout << (!(a == b) || !(g != 5)) << !(a == b && g != 5) << " | ";
		std::cout << !((x <= 8) && (y > 4)) << (!(x <= 8) || !(y > 4)) << " | ";
		std::cout << !((i > 4) || (j <= 6)) << (!(i > 4) && !(y <= 6)) << std::endl;
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
