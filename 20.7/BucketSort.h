#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <exception>

class BucketSort
{
public:
	BucketSort(void) :
		bucket(std::vector<std::queue<size_t>>(10))
	{

	}
	
	void operator()(std::vector<size_t>& items)
	{
		for (auto v : items)
		{
			if (v == 0)
			{
				throw std::invalid_argument("Error. All the items must be positive\n");
			}
		}

		size_t maxPosition = getBiggestLeftmostDigitPosition(items);
		for (size_t i = 1; i <= maxPosition; ++i)
		{
			distribution(items, i);
			gathering(items);
		}
	}

private:
	std::vector<std::queue<size_t>> bucket;

	size_t getBiggestLeftmostDigitPosition(std::vector<size_t>& items)
	{
		size_t max = 0;
		for (auto& v : items)
		{
			if (!v)
			{
				throw std::invalid_argument("Error. All the items must be positive\n");
			}
			size_t newPos = getLeftmostDigitPosition(v);
			if (newPos > max)
			{
				max = newPos;
			}
		}

		return max;
	}

	size_t getLeftmostDigitPosition(size_t positiveNumber)
	{
		if (!positiveNumber)
		{
			throw std::invalid_argument("Error. The argument must be positive\n");
		}
		size_t j = 0;
		size_t i = 1;
		for (; positiveNumber / i != 0; i *= 10, ++j)
		{
		}
		return j;
	}

	size_t getDigitAtPosition(size_t number, size_t digitPositionFromRight /* 1 for ones, 2 for tens...*/)
	{
		size_t numberToModulo = 10;
		size_t numberToDevide = 1;

		for (size_t i = 1; i < digitPositionFromRight; ++i)
		{
			numberToModulo *= 10;
			numberToDevide *= 10;
		}

		if (number >= numberToModulo)
		{
			return number % numberToModulo / numberToDevide;
		}
		else
		{
			return number / numberToDevide;
		}
	}

	void distribution(std::vector<size_t>& items, size_t digitPositionFromRight)
	{
		for (auto& v : items)
		{
			size_t position = getDigitAtPosition(v, digitPositionFromRight);
			bucket.at(position).push(v);
		}
	}

	void gathering(std::vector<size_t>& items)
	{
		size_t i = 0;
		for (auto& que : bucket)
		{
			while (!que.empty())
			{
				size_t temp = que.front();
				que.pop();
				items.at(i++) = temp;
			}
		}
	}
};