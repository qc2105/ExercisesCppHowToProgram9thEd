#pragma once
#include <stdexcept>

class OverflowError :
	public std::runtime_error
{
public:

	OverflowError() :
		std::runtime_error("Arithmetic overflow error")
	{

	}
	virtual ~OverflowError() {}
};

