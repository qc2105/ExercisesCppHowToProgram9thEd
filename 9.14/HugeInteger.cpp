#include "HugeInteger.h"
#include <iostream>

HugeInteger::HugeInteger(const std::string &numberString):
	digits(std::array<int, nDigits>()),
	sign('+')
{
	input(numberString);
}

HugeInteger::HugeInteger(const HugeInteger & b):
	digits(b.digits),
	sign(b.sign)
{
	*this = b;
}

void HugeInteger::input(const std::string &numberString)
{
	size_t strLength = numberString.length();
	for (size_t i = strLength - 1, j = nDigits - 1; i != 0; i--, j--)
	{
		digits.at(j) = numberString.at(i) - '0';
	}
	if (numberString.at(0) == '+' || numberString.at(0) == '-')
	{
		sign = numberString.at(0);
	}
	else
	{
		digits.at(nDigits - strLength) = numberString.at(0) - '0';
		sign = '+';
	}
}

std::string HugeInteger::output(void) const
{
	size_t i = 0;
	
	for (; digits[i] == 0; i++)
	{
		std::cout << ' ';
	}
	std::cout << sign;
	for (; i < digits.size(); i++)
	{
		std::cout << digits[i];
	}
	std::cout << std::endl;

	return std::string();
}

HugeInteger & HugeInteger::add(const HugeInteger &b)
{
	// TODO: insert return statement here
	if (this->sign == b.sign)
	{
		this->absoluteAdd(b);
		return *this;
	}
	else 
	{
		if (isAbsoluteNotLessThan(b))
		{
			for (int i = nDigits - 1; i >= 0; i--)
			{
				if (this->digits[i] >= b.digits[i])
				{
					this->digits[i] -= b.digits[i];
				}
				else
				{
					if (i >= 1)
					{
						this->digits[i - 1] -= 1;
						this->digits[i] += 10;
					}
					this->digits[i] -= b.digits[i];
				}
			}

			return *this;
		}
		else
		{
			HugeInteger temp(b);
			for (int i = nDigits - 1; i >= 0; i--)
			{
				if (temp.digits[i] >= this->digits[i])
				{
					temp.digits[i] -= this->digits[i];
				}
				else
				{
					if (i >= 1)
					{
						temp.digits[i - 1] -= 1;
						temp.digits[i] += 10;
					}
					temp.digits[i] -= this->digits[i];
				}
			}

			*this = temp;
			return *this;
		}
	}
	return *this;
}

HugeInteger & HugeInteger::subtract(const HugeInteger & b)
{
	// TODO: insert return statement here
	HugeInteger temp(b);
	if (b.sign == '-')
	{
		temp.sign = '+';
	}
	else
	{
		temp.sign = '-';
	}

	return this->add(temp);
}

HugeInteger & HugeInteger::operator=(const HugeInteger & b)
{
	// TODO: insert return statement here
	this->sign = b.sign;
	for (size_t i = 0; i < nDigits; i++)
	{
		this->digits[i] = b.digits[i];
	}

	return *this;
}

HugeInteger & HugeInteger::absoluteAdd(const HugeInteger & b)
{
	// TODO: insert return statement here
	for (int i = nDigits - 1; i >= 0; i--)
	{
		this->digits[i] += b.digits[i];
		if (this->digits[i] > 10)
		{
			if (i >= 1)
			{
				this->digits[i - 1] += 1;
			}
			this->digits[i] -= 10;
		}
	}

	return *this;
}

bool HugeInteger::isAbsoluteNotLessThan(const HugeInteger & b) const
{
	for (size_t i = 0; i < nDigits; i++)
	{
		if (this->digits[i] > b.digits[i])
		{
			return true;
		}
		else if (this->digits[i] < b.digits[i])
		{
			return false;
		}
	}
	return true;
}

bool HugeInteger::isEqualTo(const HugeInteger & b) const
{
	if (this->sign != b.sign)
	{
		return false;
	}
	for (size_t i = 0; i < nDigits; i++)
	{
		if (this->digits[i] != b.digits[i])
		{
			return false;
		}
	}

	return true;
}

bool HugeInteger::isNotEqualTo(const HugeInteger & b) const
{
	return !isEqualTo(b);
}

bool HugeInteger::isGreaterThan(const HugeInteger & b) const
{
	if (this->sign == b.sign)
	{
		if (isAbsoluteNotLessThan(b))
		{
			if (this->sign == '+')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (this->sign == '-')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if (this->sign == '+')
	{
		return true;
	}
	
	return false;
}

bool HugeInteger::isLessThan(const HugeInteger & b) const
{
	return (!isGreaterThan(b)) && (!isEqualTo(b));
}

bool HugeInteger::isGreateThanOrEqualTo(const HugeInteger & b) const
{
	return !isLessThan(b);
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger & b) const
{
	return !isGreaterThan(b);
}

bool HugeInteger::isZero(void) const
{
	for (size_t i = 0; i < nDigits; i++)
	{
		if (this->digits[i] != 0)
		{
			return false;
		}
	}
	return true;
}
