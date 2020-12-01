#pragma once
#include <stdexcept>

class DevideByZeroError :
	public std::runtime_error
{
public:

	DevideByZeroError():
		std::runtime_error("Devide by zero error")
	{

	}
	virtual ~DevideByZeroError() {}
};

