#include "Rational.h"
#include <cmath>
#include <iostream>

Rational::Rational(const int _numerator, const int _denominator)
	:numerator(_numerator),
	denominator(_denominator)
{
	if (!isValid())
	{
		throw "Invalid, zero denominator";
	}
	reduce();
}

Rational & Rational::add(const Rational &b)
{
	// TODO: insert return statement here
	unsigned leastCommonMultiple = lcm(abs(this->denominator), abs(b.denominator));

	this->numerator *= leastCommonMultiple / abs(this->denominator);
	this->numerator += b.numerator * (leastCommonMultiple / abs(b.denominator));
	this->denominator = leastCommonMultiple;
	
	if (!isValid())
	{
		throw "Invalid, zero denominator";
	}

	reduce();

	return *this;
}

Rational & Rational::substract(const Rational &b)
{
	// TODO: insert return statement here
	unsigned leastCommonMultiple = lcm(abs(this->denominator), abs(b.denominator));

	this->numerator *= leastCommonMultiple / abs(this->denominator);
	this->numerator -= b.numerator * (leastCommonMultiple / abs(b.denominator));
	this->denominator = leastCommonMultiple;

	if (!isValid())
	{
		throw "Invalid, zero denominator";
	}

	reduce();

	return *this;
}

Rational & Rational::multiply(const Rational &b)
{
	// TODO: insert return statement here
	this->numerator *= b.numerator;
	this->denominator *= b.denominator;

	if (!isValid())
	{
		throw "Invalid, zero denominator";
	}

	reduce();

	return *this;
}

Rational & Rational::divide(const Rational &b)
{
	// TODO: insert return statement here
	this->numerator *= b.denominator;
	this->denominator *= b.numerator;

	if (!isValid())
	{
		throw "Invalid, zero denominator";
	}

	reduce();

	return *this;
}

bool Rational::operator==(const Rational &right) const
{
	if (getDenominator() != right.getDenominator() || getNumerator() != right.getNumerator())
	{
		return false;
	}
	return true;
}

bool Rational::operator>(const Rational &right) const 
{
	Rational temp = *this - right;
	
	if (temp.getDenominator() * temp.getNumerator() > 0)
	{
		return true;
	}

	return false;
}

Rational Rational::operator+(const Rational &right) const 
{
	Rational temp(*this);
	temp.add(right);

	return temp;
}

Rational Rational::operator-(const Rational &right) const
{
	Rational temp(*this);
	temp.substract(right);
	
	return temp;
}

Rational Rational::operator*(const Rational &right) const
{
	Rational temp(*this);
	temp.multiply(right);

	return temp;
}

Rational Rational::operator/(const Rational &right) const
{
	Rational temp(*this);
	temp.divide(right);

	return temp;
}

void Rational::print() const
{
	if (0 == denominator)
	{
		std::cout << "Error, zero denorminator\n";
	}
	else
	{
		std::cout << numerator << "/" << denominator << std::endl;
	}
}

void Rational::printFloat() const
{
	if (0 == denominator)
	{
		std::cout << "Error, zero denorminator\n";
	}
	else
	{
		std::cout << static_cast<double>(numerator) / static_cast<double>(denominator) << std::endl;
	}
}

unsigned Rational::gcd(unsigned n, unsigned m) const
{
	unsigned temp = n;
	if (n < m)
	{
		temp = n;
		n = m;
		m = temp;
	}

	unsigned greatestCommanDivisor = 1;
	for (unsigned i = 1; i <= m; i++)
	{
		if (0 == n % i && 0 == m % i)
		{
			greatestCommanDivisor = i;
		}
	}

	return greatestCommanDivisor;
}

unsigned Rational::lcm(unsigned a, unsigned b) const
{
	unsigned max = 0, min = 0;
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}

	for (unsigned int i = 1; i <= min; i++)
	{
		if (0 == ((max * i) % min))
		{
			return max * i;
		}
	}

	return a * b;
}

bool Rational::isValid() const
{
	return !(0 == denominator);
}

void Rational::reduce()
{
	unsigned greatestCommonDivisor = gcd(abs(numerator), abs(denominator));

	numerator /= static_cast<int>(greatestCommonDivisor);
	denominator /= static_cast<int>(greatestCommonDivisor);

	if (denominator < 0)
	{
		denominator = -denominator;
		numerator = -numerator;
	}
}
