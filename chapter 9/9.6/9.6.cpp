// 9.6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rational.h"

int main()
{
    std::cout << "Hello World!\n";

	try
	{
		Rational a(1, 2), b(15, 20), c(4, 16), d(2, 5);

		a.add(b).substract(c).add(d).multiply(b).divide(c).print();
		Rational good(1, 4);
		good.printFloat();
		Rational ill(9, 0);
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
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
