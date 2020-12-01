// 6.41.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <string>

unsigned gcd(unsigned a, unsigned b);
unsigned gcd_r(unsigned a, unsigned b);
unsigned gcd_r_big_small(unsigned big, unsigned small);

unsigned gcd(unsigned n, unsigned m)
{
	unsigned temp = n;
	if (n < m)
	{
		temp = n;
		n = m;
		m = temp;
	}

	unsigned greatestCommanDivisor = 1;
	for (unsigned i = 1; i <= m; i++)
	{
		if (0 == n % i && 0 == m % i)
		{
			greatestCommanDivisor = i;
		}
	}

	return greatestCommanDivisor;
}

unsigned gcd_r(unsigned n, unsigned m)
{
	unsigned temp = n;
	if (n < m)
	{
		temp = n;
		n = m;
		m = temp;
	}

	return gcd_r_big_small(n, m);
}

unsigned gcd_r_big_small(unsigned big, unsigned small)
{
	if (0 == small)
	{
		return big;
	}
	else
	{
		return gcd_r_big_small(small, big % small);
	}
}

int main()
{
	srand(static_cast<unsigned>(time(0)));

	size_t width = std::to_string(INT_MAX).size() + 1;

	for (int i = 0; i < 1000; i++)
	{
		unsigned a = rand() % INT_MAX + 1;
		unsigned b = rand() % INT_MAX + 1;
		/*unsigned a = rand() % 20 + 1;
		unsigned b = rand() % 20 + 1;*/

		unsigned iterative = gcd(a, b);
		unsigned recursive = gcd_r(a, b);
		assert(iterative == recursive);
		std::cout << std::setw(5) << "ID" << std::setw(width) << "a" << std::setw(width) << "b" 
			<< std::setw(width) << "iterative" << std::setw(width) << "recursive" << '\n';
		std::cout << std::setw(5) << i << std::setw(width) << a << std::setw(width) << b 
			<< std::setw(width) << iterative << std::setw(width) << recursive << '\n';
		std::cout << '\n';
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
