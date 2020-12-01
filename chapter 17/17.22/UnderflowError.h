#pragma once
#include <stdexcept>

class UnderflowError :
	public std::runtime_error
{
public:

	UnderflowError() :
		std::runtime_error("Arithmetic underflow error")
	{

	}
	virtual ~UnderflowError() {}
};

