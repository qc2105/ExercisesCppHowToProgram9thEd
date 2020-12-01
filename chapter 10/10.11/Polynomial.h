#pragma once
#include <vector>
#include <cmath>
#include <iostream>

const double tolerance = 1.0e-8;

class Term
{
public:
	explicit Term(double coefficeint = 0, unsigned exponent = 0);

	double getCoefficient(void) const
	{
		return coefficient;
	}
	unsigned getExponent(void) const
	{
		return exponent;
	}
	void setCoefficeint(double _coefficient)
	{
		coefficient = _coefficient;
	}
	void setExponent(unsigned _exponent)
	{
		exponent = _exponent;
	}

	Term operator* (const Term&) const;
	Term operator*= (const Term&);

	bool operator< (const Term&right) const
	{
		return this->getExponent() < right.getExponent();
	}

	bool operator== (const Term&right) const
	{
		return ::fabs(this->getCoefficient() - right.getCoefficient()) < tolerance && this->getExponent() == right.getExponent();
	}

private:
	double coefficient;
	unsigned exponent;
};

bool termComplare(const Term &a, const Term &b);

class Polynomial
{

friend std::ostream & operator<< (std::ostream &out, const Polynomial& poly);
friend std::istream & operator>> (std::istream &in, Polynomial& poly);

public:
	explicit Polynomial(const std::vector<Term> &terms);
	Polynomial();

	void setTerms(const std::vector<Term> &terms);
	void getTerms(std::vector<Term> &outputTerms) const
	{
		outputTerms.clear();
		outputTerms = terms;
	}

	unsigned getOrder(void) const
	{
		if (terms.size() > 0)
		{
			return terms.at(0).getExponent();
		}
		return 0;
	}

	Polynomial operator+ (const Polynomial &) const;
	Polynomial operator+= (const Polynomial &);
	Polynomial operator- (const Polynomial &) const;
	Polynomial operator-= (const Polynomial &);
	Polynomial operator* (const Polynomial &) const;
	Polynomial operator*= (const Polynomial &);
	Polynomial operator* (const Term&) const;
	Polynomial operator*= (const Term&);

	//const return to avoid (a = b) = c;
	const Polynomial &operator= (const Polynomial &right)
	{
		if (this == &right)
		{
			return *this;
		}
		this->terms = right.terms;
		return *this;
	}

	bool operator== (const Polynomial &right) const
	{
		return this->terms == right.terms;
	}

private:
	void sortTerms(void);
	void reduceTerms(void);

	std::vector<Term> terms;
};


std::ostream & operator<< (std::ostream &out, const Polynomial& poly);
std::istream & operator>> (std::istream &in, Polynomial& poly);