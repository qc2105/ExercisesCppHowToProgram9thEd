#pragma once
class Rational
{
public:
	explicit Rational(const int = 1, const int = 1);

	Rational &add(const Rational &);
	Rational &substract(const Rational &);
	Rational &multiply(const Rational &);
	Rational &divide(const Rational &);

	void print() const;
	void printFloat() const;

private:
	unsigned gcd(unsigned, unsigned ) const;
	void reduce();
	unsigned lcm(unsigned, unsigned ) const;
	bool isValid() const;
	
	int numerator;
	int denominator;
};

