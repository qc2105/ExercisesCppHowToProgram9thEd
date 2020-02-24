#include "Complex.h"
#include <cctype>
#include "Complex.h"
#include <string>

Complex::Complex()
	:real(0),
	imaginary(0),
	inGoodState(true)
{
}

Complex::Complex(int Real, int Imaginary)
	:real(Real),
	imaginary(Imaginary),
	inGoodState(true)
{
}

void Complex::removeSpaces(std::string & s) const
{
	std::string stringWithNoSpace;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s.at(i) != ' ')
		{
			stringWithNoSpace.push_back(s.at(i));
		}
	}

	s = stringWithNoSpace;
}

bool Complex::fectchNextInteger(const std::string & s, size_t & index, int & integer) const
{
	if (s.empty())
	{
		return false;
	}
	bool isPositive = true;
	if (s.at(index) == '+')
	{
		isPositive = true;
		++index;
	}
	else if (s.at(index) == '-')
	{
		isPositive = false;
		++index;
	}
	else if (::isdigit(s.at(index)))
	{
		isPositive = true;
	}
	else
	{
		//invalid string
		return false;
	}

	if (index == s.size() - 1 && s.at(index) == 'i')
	{
		isPositive ? integer = 1 : integer = -1;
		return true;
	}

	std::string digits;
	for (; index < s.size() && ::isdigit(s.at(index)); ++index)
	{
		digits.push_back(s.at(index));
	}

	if (digits.empty())
	{
		return false;
	}
	isPositive ? integer = std::stoi(digits) : integer = -std::stoi(digits);

	return true;
}

std::ostream & operator << (std::ostream &output, const Complex & c)
{
	output.clear();
	if (c.inGoodState)
	{
		if (c.real == 0 && c.imaginary == 0)
		{
			output << 0;
		}
		if (c.real)
		{
			output << c.real;
		}
		if (c.real && c.imaginary)
		{
			if (c.imaginary == 1)
			{
				output << "+i";
			}
			else if (c.imaginary == -1)
			{
				output << "-i";
			}
			else
			{
				output << std::showpos << c.imaginary << "i";
			}
		}
		else if (!c.real && c.imaginary)
		{
			if (c.imaginary == 1)
			{
				output << 'i';
			}
			else if (c.imaginary == -1)
			{
				output << "-i";
			}
			else
			{
				output << std::noshowpos << c.imaginary << "i";
			}
		}
	}
	else
	{
		output.clear(std::ios_base::failbit);
	}
	return output;
}

std::istream & operator >> (std::istream &input, Complex & c)
{
	input.clear();

	std::string inputStr;
	std::getline(input, inputStr);
	c.removeSpaces(inputStr);

	if (inputStr.size() == 1 && inputStr.at(0) == 'i')
	{
		c.real = 0;
		c.imaginary = 1;
		c.inGoodState = true;
		return input;
	}

	size_t index = 0;
	if (!c.fectchNextInteger(inputStr, index, c.real))
	{
		input.clear(std::ios_base::failbit);
		c.inGoodState = false;
		return input;
	}

	if (index == inputStr.size())
	{
		c.imaginary = 0;
		c.inGoodState = true;
		return input;
	}
	else if (index == inputStr.size() - 1 && inputStr.at(index) == 'i') // 8i, -8i
	{
		c.imaginary = c.real;
		c.real = 0;
		c.inGoodState = true;
		return input;
	}

	if (!c.fectchNextInteger(inputStr, index, c.imaginary))
	{
		input.clear(std::ios_base::failbit);
		c.inGoodState = false;
		return input;
	}

	if (index == inputStr.size())
	{
		input.clear(std::ios_base::failbit);
		c.inGoodState = false;
		return input;
	}

	if (index == inputStr.size() - 1 && inputStr.at(index) == 'i')
	{
		c.inGoodState = true;
		return input;
	}

	input.clear(std::ios_base::failbit);
	c.inGoodState = false;
	return input;
}
