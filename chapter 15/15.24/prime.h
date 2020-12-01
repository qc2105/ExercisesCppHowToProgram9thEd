#pragma once
#include <bitset>
#include <vector>
#include <set>

bool getPrimes(int upper_bound, std::bitset<10000>& numbers);
bool getPrimes(int upper_bound, std::vector<size_t>& primes);
bool getPrimes(int upper_bound, std::bitset<10000>& outBset, std::vector<size_t>& outPrimes);
bool getUniquePrimesFactors(int inputNumber, std::vector<size_t> &primeFactors);
bool getPrimesFactors(int inputNumber, std::set<size_t>& primeFactors);

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

bool getPrimes(int upper_bound, std::vector<size_t>& primes)
{
	if (upper_bound > 10000)
	{
		throw("upper_bound out of range\n");
		return false;
	}

	std::bitset<10000> numbers;
	numbers.set();
	numbers.reset(0);

	for (int i = 2; i < upper_bound; ++i)
	{
		if (numbers[i] == 1)
		{
			for (int j = 2; i * j < upper_bound; j++)
			{
				numbers[static_cast<size_t>(i)* j] = 0;
			}
		}
	}

	for (int i = 2; i < upper_bound; ++i)
	{
		if (numbers[i])
		{
			primes.push_back(i);
		}
	}
	primes.push_back(1);

	return true;
}

inline bool getPrimes(int upper_bound, std::bitset<10000>& numbers, std::vector<size_t>& primes)
{
	if (upper_bound > 10000)
	{
		throw("upper_bound out of range\n");
		return false;
	}

	numbers.set();
	numbers.reset(0);

	for (int i = 2; i < upper_bound; ++i)
	{
		if (numbers[i] == 1)
		{
			for (int j = 2; i * j < upper_bound; j++)
			{
				numbers[static_cast<size_t>(i)* j] = 0;
			}
		}
	}

	for (int i = 2; i < upper_bound; ++i)
	{
		if (numbers[i])
		{
			primes.push_back(i);
		}
	}
	primes.push_back(1);

	return true;
}

inline bool getUniquePrimesFactors(int inputNumber, std::vector<size_t>& outputPrimeFactors)
{
	std::bitset<10000> bset;
	std::vector<size_t> primes;
	if (!getPrimes(inputNumber+1, bset, primes))
	{
		return false;
	}

	if (!bset[inputNumber])
	{
		for (auto v : primes)
		{

			if (inputNumber % v == 0)
			{
				outputPrimeFactors.push_back(v);
				if (!getUniquePrimesFactors(inputNumber / static_cast<int>(v), outputPrimeFactors))
				{
					return false;
				}
				break;
			}

		}
	}
	else
	{
		outputPrimeFactors.push_back(inputNumber);
	}

	return true;
}

inline bool getPrimesFactors(int inputNumber, std::set<size_t>& outputPrimeFactors)
{
	std::bitset<10000> bset;
	std::vector<size_t> primes;
	if (!getPrimes(inputNumber + 1, bset, primes))
	{
		return false;
	}

	if (!bset[inputNumber])
	{
		for (auto v : primes)
		{

			if (inputNumber % v == 0)
			{
				outputPrimeFactors.insert(v);
				if (!getPrimesFactors(inputNumber / static_cast<int>(v), outputPrimeFactors))
				{
					return false;
				}
				break;
			}

		}
	}
	else
	{
		outputPrimeFactors.insert(inputNumber);
	}

	return true;
}
