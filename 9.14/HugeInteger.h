#pragma once
#include <array>
#include <string>

const int nDigits = 40;

class HugeInteger
{
public:
	explicit HugeInteger(const std::string &numberString = std::string("0"));
	HugeInteger(const HugeInteger &b);

	void input(const std::string &numberString = std::string("0"));
	std::string output(void) const;
	HugeInteger& add(const HugeInteger &b);
	HugeInteger& subtract(const HugeInteger &b);
	HugeInteger& multiply(const HugeInteger &b);
	HugeInteger& divide(const HugeInteger &b);
	HugeInteger& modulus(const HugeInteger &);

	bool isEqualTo(const HugeInteger &b) const;
	bool isNotEqualTo(const HugeInteger &b) const;
	bool isGreaterThan(const HugeInteger &b) const;
	bool isLessThan(const HugeInteger &b)const;
	bool isGreateThanOrEqualTo(const HugeInteger &b) const;
	bool isLessThanOrEqualTo(const HugeInteger &b) const;
	bool isZero(void) const;

	std::array<int, nDigits> digits;
	char sign;

	HugeInteger &operator = (const HugeInteger&b);
private:
	HugeInteger& absoluteAdd(const HugeInteger &b);
	
	bool isAbsoluteNotLessThan(const HugeInteger &b) const;
};

