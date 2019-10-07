// Chapter6-self-review-6.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
 	if (::fabs(::ceil(9.2)- 10.0) < DBL_TRUE_MIN)
	{
		std::cout << std::setw(5) << "ceil" << " passed.\n";
	}
	else
	{
		std::cout << std::setw(5) << "ceil" << " failed.\n";
	}

	if (::fabs(1.0 - ::cos(0.0)) < DBL_TRUE_MIN)
	{
		std::cout << std::setw(5) << "cos" << " passed.\n";
	}
	else
	{
		std::cout << std::setw(5) << "cos" << " failed.\n";
	}

	if (1.0 == ::fabs(1.0))
	{
		std::cout << std::setw(5) << "fabs" << " passed.\n";
	}
	else
	{
		std::cout << std::setw(5) << "fabs" << " failed.\n";
	}

	if (::fabs(9.0 - ::floor(9.2)) < DBL_TRUE_MIN)
	{
		std::cout << std::setw(5) << "floor" << " passed.\n";
	}
	else
	{
		std::cout << std::setw(5) << "floor" << " failed.\n";
	}

	if (::fabs(0.2 - fmod(2.6, 1.2)) < 0.0001)
	{
		std::cout << std::setw(5) << "fmod" << " passed.\n";
	}
	else
	{
		std::cout << std::setw(5) << "fmod" << " failed.\n";
	}

	if (::fabs(1.0 - ::log(2.718282)) < 0.0001)
	{
		std::cout << std::setw(5) << "log" << " passed.\n";
	}
	else
	{
		std::cout << std::setw(5) << "log" << " failed\n";
	}

	if (128 == ::pow(2,7))
	{
		std::cout << std::setw(5) << "pow" << " passed.\n";
	}
	else
	{
		std::cout << std::setw(5) << "pow" << " failed.\n";
	}

	if (0 == ::sin(0.0))
	{
		std::cout << std::setw(5) << "sin" << " passed.\n";
	}
	else
	{
		std::cout << std::setw(5) << "sin" << " failed.\n";
	}

	if (::fabs(3.0 - ::sqrt(9.0)) < 0.0001)
	{
		std::cout << std::setw(5) << "sqrt" << " passed.\n";
	}
	else
	{
		std::cout << std::setw(5) << "sqrt" << " failed\n";
	}

	if (0 == ::tan(0.0))
	{
		std::cout << std::setw(5) << "tan" << " passed.\n";
	}
	else
	{
		std::cout << std::setw(5) << "tan" << " failed.\n";
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
