#pragma once
#include <vector>

class Clock
{
	friend void operator++(Clock& b);
public:

	Clock(size_t n, int _maxV = 5) :
		clock(std::vector<int>(static_cast<size_t>(::pow(2, n) - 1), 0)),
		nSize(static_cast<size_t>(::pow(2, n) - 1)),
		nMaxV(_maxV)
	{

	}

	const size_t size() const
	{
		return nSize;
	}

	int& at(size_t i)
	{
		return clock.at(i);
	}

	const int at(size_t i) const
	{
		return clock.at(i);
	}

	const int maxV(void) const
	{
		return nMaxV;
	}

	void addOneAtPos(size_t i);

	const std::vector<int>& vec(void) const
	{
		return clock;
	}

	bool operator== (const Clock& b) const
	{
		return this->clock == b.clock && this->nSize == b.nSize && this->nMaxV == b.nMaxV;
	}

private:
	std::vector<int> clock;
	size_t nSize;
	int nMaxV;
};

