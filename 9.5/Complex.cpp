#include "Complex.h"
#include <iostream>

Complex::Complex(double _realPart, double _imaginaryPart)
	:realPart(_realPart),
	imaginaryPart(_imaginaryPart)
{

}

Complex & Complex::add(Complex b)
{
	// TODO: insert return statement here
	this->realPart += b.realPart;
	this->imaginaryPart += b.imaginaryPart;

	return *this;
}

Complex & Complex::substract(Complex b)
{
	// TODO: insert return statement here
	this->realPart -= b.realPart;
	this->imaginaryPart -= b.imaginaryPart;

	return *this;
}

void Complex::print() const
{
	std::cout << "(" << realPart << ", " << imaginaryPart << ")" << std::endl;
}
