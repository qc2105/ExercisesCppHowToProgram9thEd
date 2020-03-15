#pragma once
#include <bitset>

bool getPrimes(int upper_bound, std::bitset<10000>& numbers);

bool getPrimes(int upper_bound, std::bitset<10000>& numbers)
{
	if (upper_bound > 10000)
	{
		throw("upper_bound out of range\n");
		return false;
	}

	numbers.set();
	numbers.reset(0);

	for (int i = 2; i < upper_bound; i++)
	{
		if (numbers[i] == 1)
		{
			for (int j = 2; i * j < upper_bound; j++)
			{
				numbers[static_cast<size_t>(i)* j] = 0;
			}
		}
	}

	return true;
}