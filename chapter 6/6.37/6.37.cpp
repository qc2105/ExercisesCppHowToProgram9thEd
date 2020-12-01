// 6.37.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <string>

unsigned gcd(unsigned a, unsigned b);
unsigned gcd_r(unsigned big, unsigned small);
unsigned lcm(unsigned a, unsigned b);
unsigned lcm_gcd(unsigned n, unsigned m);
unsigned lcm_r(unsigned a, unsigned b);

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

unsigned gcd_r(unsigned big, unsigned small)
{
	if (0 == small)
	{
		return big;
	}
	else
	{
		return gcd_r(small, big % small);
	}
}

unsigned lcm_r(unsigned n, unsigned m)
{
	unsigned temp = n;
	if (n < m)
	{
		temp = n;
		n = m;
		m = temp;
	}

	if (1 == gcd(n, m))
	{
		return n * m;
	}
	else
	{
		return gcd(n, m) * lcm_r(n / gcd(n, m), m / gcd(n, m));
	}
}

unsigned lcm_gcd(unsigned n, unsigned m)
{
	unsigned temp = n;
	if (n < m)
	{
		temp = n;
		n = m;
		m = temp;
	}

	unsigned theGcd = gcd_r(n, m);

	return n * m / theGcd;
}

unsigned lcm(unsigned a, unsigned b)
{
	unsigned max = 0, min = 0;
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}

	for (unsigned int i = 1; i <= min; i++)
	{
		if (0 == ((max * i) % min))
		{
			return max * i;
		}
	}

	return a * b;
}

int main()
{
	unsigned n, m;
	srand(static_cast<unsigned>(time(0)));

	int i = 0;
	while (i < 1000)
	{
		n = rand() % static_cast<int>(sqrt(INT_MAX)) + 1;
		m = rand() % static_cast<int>(sqrt(INT_MAX)) + 1;
		unsigned iterative = lcm(n, m);
		unsigned lcmGcd = lcm_gcd(n, m);
		unsigned recursive = lcm_r(n, m);
		assert(iterative == recursive);
		assert(recursive == lcmGcd);
		size_t width = std::to_string(UINT32_MAX).size() + 1;
		std::cout << std::setw(5) << "id" << std::setw(width) << "n" << std::setw(width) << "m" << std::setw(width)
			<< "iterative" << std::setw(width) << "recursive" << std::setw(width) << "lcmGcd" << '\n';
		std::cout << std::setw(5) << i << std::setw(width) << n << std::setw(width) << m << std::setw(width) 
			<< iterative << std::setw(width) << recursive << std::setw(width) << lcmGcd << '\n';
		std::cout << "\n";
		i++;
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
