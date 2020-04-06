#include "Clock.h"

void operator++(Clock& b)
{
	b.addOneAtPos(0);
}

void Clock::addOneAtPos(size_t i)
{
	if (i == size() - 1 )
	{
		if (this->at(i) != maxV())
		{
			this->at(i) += 1;
		}
		else
		{
			this->at(i) = 0;
		}
	}
	else
	{
		if (this->at(i) != maxV())
		{
			this->at(i) += 1;
		}
		else
		{
			this->at(i) = 0;
			addOneAtPos(i + 1);
		}
	}
}
