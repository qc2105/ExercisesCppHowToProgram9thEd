// 15.24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include "prime.h"
#include <stdexcept>
#include <iterator>

int main()
{
	std::bitset<10000> primes;
	try
	{
		if (!getPrimes(1024, primes))
		{
			std::cout << "1024 is too big\n";
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}

	for (size_t i = 0; i < 1024; ++i)
	{
		if (primes[i])
		{
			std::cout << i << " ";
		}
	}
	
	std::cout << std::endl;

	std::cout << "intput a number in range (0, 10000): \n";
	int number = 0;
	std::cin >> number;
	if (!std::cin || number < 0 || number >= 10000 || !getPrimes(number+1, primes))
	{
		std::cerr << "invalid input\n";
		exit(EXIT_FAILURE);
	}
	
	std::cout << std::boolalpha << static_cast<bool>(primes[number]) << std::endl;

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
