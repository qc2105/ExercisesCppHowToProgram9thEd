#include "Point.h"
#include <cctype>
#include <string>

Point::Point()
	:xCoordinate(0),
	yCoordinate(0),
	inGoodSate(true)
{
}

Point::Point(int x, int y)
	:xCoordinate(x),
	yCoordinate(y),
	inGoodSate(true)
{
}

bool Point::areDigits(const std::string s) const
{
	if (s.empty())
	{
		return false;
	}
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (!isdigit(s.at(i)))
		{
			return false;
		}
	}
	return true;
}

std::istream & operator>>(std::istream & input, Point & point)
{
	input.clear();
	std::string inputStr;
	input >> inputStr;
	if (inputStr.empty())
	{
		input.clear(std::ios_base::failbit);
		point.inGoodSate = false;
		return input;
	}
	if (inputStr.at(0) == '(')
	{
		if (inputStr.at(inputStr.size() - 1) != ')')
		{
			input.clear(std::ios_base::failbit);
			point.inGoodSate = false;
			return input;
		}
		size_t commaPos = inputStr.find(',');
		if ( commaPos == std::string::npos)
		{
			input.clear(std::ios_base::failbit);
			point.inGoodSate = false;
			return input;
		}
		else
		{
			char xSign = '0', ySign = '0';
			std::string xString = inputStr.substr(1, commaPos - 1);
			std::string yString = inputStr.substr(commaPos + 1, inputStr.size() - commaPos - 2);
			if (xString.at(0) == '+' || xString.at(0) == '-')
			{
				xSign = xString.at(0);
				xString = xString.substr(1, xString.size() - 1);
			}
			if (yString.at(0) == '+' || yString.at(0) == '-')
			{
				ySign = yString.at(0);
				yString = yString.substr(1, yString.size() - 1);
			}
			if (!point.areDigits(xString) || !point.areDigits(yString))
			{
				input.clear(std::ios_base::failbit);
				point.inGoodSate = false;
				return input;
			}
			point.xCoordinate = std::stoi(xSign + xString);
			point.yCoordinate = std::stoi(ySign + yString);
			point.inGoodSate = true;
			return input;
		}
	}
	else
	{
		size_t commaPos = inputStr.find(',');
		if (commaPos == std::string::npos)
		{
			input.clear(std::ios_base::failbit);
			point.inGoodSate = false;
			return input;
		}
		else
		{
			std::string xString = inputStr.substr(0, commaPos);
			std::string yString = inputStr.substr(commaPos + 1, inputStr.size() - commaPos - 1);
			if (!point.areDigits(xString) || !point.areDigits(yString))
			{
				input.clear(std::ios_base::failbit);
				point.inGoodSate = false;
				return input;
			}
			point.xCoordinate = std::stoi(xString);
			point.yCoordinate = std::stoi(yString);
			point.inGoodSate = true;
			return input;
		}
	}
	input.clear(std::ios_base::failbit);
	point.inGoodSate = false;
	return input;
}

std::ostream & operator<<(std::ostream & output, const Point & point)
{
	output.clear();
	if (point.inGoodSate)
	{
		output << '(' << point.xCoordinate << "," << point.yCoordinate << ')';
	}
	else
	{
		output.clear(std::ios_base::failbit);
	}
	return output;
}
