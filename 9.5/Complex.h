#pragma once
class Complex
{
public:
	explicit Complex(double = 0.0, double = 0.0);

	Complex & add(Complex b);
	Complex & substract(Complex b);
	void print() const;
private:
	double realPart;
	double imaginaryPart;
};

