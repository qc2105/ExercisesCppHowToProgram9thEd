#include "Polynomial.h"
#include <algorithm>
#include "InputProcessor.h"

Term::Term(double _coefficeint, unsigned _exponent)
	:coefficient(_coefficeint),
	exponent(_exponent)
{
}

Term Term::operator*(const Term& right) const
{
	Term result;
	result.setCoefficeint(this->getCoefficient() * right.getCoefficient());
	result.setExponent(this->getExponent() + right.getExponent());

	return result;
}

Term Term::operator*=(const Term &right)
{
	return *this = *this * right;
}

Polynomial::Polynomial(const std::vector<Term>& _terms)
	:terms(_terms)
{
	reduceTerms();
	sortTerms();
}

Polynomial::Polynomial()
{
}

void Polynomial::setTerms(const std::vector<Term>& terms)
{
	this->terms = terms;
	reduceTerms();
	sortTerms();
}

Polynomial Polynomial::operator*(const Polynomial &right) const
{
	std::vector<Polynomial> polys;
	
	for (size_t j = 0; j < right.terms.size(); ++j)
	{
		Polynomial tempPoly = *this * right.terms.at(j);
		polys.push_back(tempPoly);
	}

	Polynomial resultPoly;
	for (size_t i = 0; i < polys.size(); ++i)
	{
		resultPoly += polys.at(i);
	}
	return resultPoly;
}

Polynomial Polynomial::operator*=(const Polynomial &right)
{
	return *this = *this * right;
}

Polynomial Polynomial::operator*(const Term &term) const
{
	Polynomial temp(*this);
	std::vector<Term> tempTerms;
	temp.getTerms(tempTerms);
	for (size_t i = 0; i < tempTerms.size(); ++i)
	{
		tempTerms.at(i) *= term;
	}
	temp.setTerms(tempTerms);

	return temp;
}

Polynomial Polynomial::operator*=(const Term &term)
{
	return *this = *this * term;
}

Polynomial Polynomial::operator+(const Polynomial &right) const
{
	//getThe bigger order
	unsigned biggerOder = this->getOrder();
	if (right.getOrder() > biggerOder)
	{
		biggerOder = right.getOrder();
	}

	std::vector<double> tempThisCoefficients = std::vector<double>(biggerOder + 1);
	for (size_t i = 0; i < this->terms.size(); i++)
	{
		tempThisCoefficients.at(this->terms.at(i).getExponent()) = this->terms.at(i).getCoefficient();
	}

	std::vector<double> tempRightCoefficients = std::vector<double>(biggerOder + 1);
	for (size_t i = 0; i < right.terms.size(); i++)
	{
		tempRightCoefficients.at(right.terms.at(i).getExponent()) = right.terms.at(i).getCoefficient();
	}

	std::vector<double> tempResultCoefficients = std::vector<double>(biggerOder + 1);
	for (size_t i = 0; i < tempResultCoefficients.size(); ++i)
	{
		tempResultCoefficients.at(i) = tempThisCoefficients.at(i) + tempRightCoefficients.at(i);
	}

	std::vector<Term> resultTerms;
	for (size_t i = 0; i < tempResultCoefficients.size(); ++i)
	{
		if (fabs(0 - tempResultCoefficients.at(i)) > tolerance)
		{
			Term tempTerm(tempResultCoefficients.at(i), static_cast<unsigned>(i));
			resultTerms.push_back(tempTerm);
		}
	}

	Polynomial resultPoly;
	resultPoly.setTerms(resultTerms);

	return resultPoly;
}

Polynomial Polynomial::operator+=(const Polynomial &right)
{
	return *this = *this + right;
}

Polynomial Polynomial::operator-(const Polynomial &right) const
{
	Polynomial temp = right;
	for (size_t i = 0; i < temp.terms.size(); ++i)
	{
		temp.terms.at(i).setCoefficeint(-right.terms.at(i).getCoefficient());
	}

	return *this + temp;
}

Polynomial Polynomial::operator-=(const Polynomial &right)
{
	return *this = *this - right;;
}

void Polynomial::sortTerms(void)
{
	std::sort(terms.rbegin(), terms.rend(), termComplare);
}

void Polynomial::reduceTerms(void)
{
	sortTerms();
	unsigned biggerOder = this->getOrder();

	std::vector<double> tempThisCoefficients = std::vector<double>(biggerOder + 1);
	for (size_t i = 0; i < this->terms.size(); i++)
	{
		tempThisCoefficients.at(this->terms.at(i).getExponent()) += this->terms.at(i).getCoefficient();
	}

	std::vector<Term> resultTerms;
	for (size_t i = 0; i < tempThisCoefficients.size(); ++i)
	{
		if (fabs(0 - tempThisCoefficients.at(i)) > tolerance)
		{
			Term tempTerm(tempThisCoefficients.at(i), static_cast<unsigned>(i));
			resultTerms.push_back(tempTerm);
		}
	}

	terms = resultTerms;
}

bool termComplare(const Term &a, const Term &b)
{
	return a < b;
}

std::ostream & operator<<(std::ostream & out, const Polynomial & poly)
{
	for (size_t i = 0; i < poly.terms.size(); ++i)
	{
		if (poly.terms.at(i).getCoefficient() > 0)
		{
			if (i != 0)
			{
				out << "+";
			}
		}
		out << poly.terms.at(i).getCoefficient();
		if (1 == poly.terms.at(i).getExponent())
		{
			out << "X";
		}
		else if (0 != poly.terms.at(i).getExponent() )
		{
			out << "X^" << poly.terms.at(i).getExponent();
		}
	}

	return out;
}

std::istream & operator>>(std::istream & in, Polynomial & poly)
{
	std::string inputString;
	in >> inputString;
	InputProcessor inp(inputString);
	std::vector<Term> inputTerms;
	inp.getTerms(inputTerms);

	poly.setTerms(inputTerms);

	return in;
}
