#pragma once
#include <iostream>

class Complex
{

public:
	Complex();
	Complex(int real, int imaginary);

	bool operator== (const Complex &c) const
	{
		return this->real == c.real && this->imaginary == c.imaginary && this->inGoodState == c.inGoodState;
	}

private:
	// can friend functions be private?
	friend std::ostream & operator << (std::ostream &output, const Complex & c);
	friend std::istream & operator >> (std::istream &input, Complex & c);
	int real;
	int imaginary;
	bool inGoodState;
	void removeSpaces(std::string &s) const;
	bool fectchNextInteger(const std::string &s, size_t &index, int &integer) const;
};

