#pragma once
class Rational
{
public:
	explicit Rational(const int = 1, const int = 1);

	Rational &add(const Rational &);
	Rational &substract(const Rational &);
	Rational &multiply(const Rational &);
	Rational &divide(const Rational &);

	bool operator==(const Rational &) const ;
	bool operator!=(const Rational &right) const
	{
		return !operator==(right);
	}
	bool operator> (const Rational &) const ;
	bool operator>= (const Rational &right) const
	{
		return operator>(right) || operator==(right);
	}
	bool operator< (const Rational &right) const
	{
		return !operator>(right) && !operator==(right);
	}
	bool operator<= (const Rational &right) const
	{
		return operator<(right) || operator==(right);
	}

	Rational operator+ (const Rational &) const;
	Rational operator- (const Rational &) const;
	Rational operator* (const Rational &) const;
	Rational operator/ (const Rational &) const;

	void print() const;
	void printFloat() const;

	int getNumerator(void) const
	{
		return this->numerator;
	}
	int getDenominator(void) const
	{
		return this->denominator;
	}

private:
	unsigned gcd(unsigned, unsigned ) const;
	void reduce();
	unsigned lcm(unsigned, unsigned ) const;
	bool isValid() const;
	
	int numerator;
	int denominator;
};

