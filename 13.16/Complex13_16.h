#pragma once
#include <iostream>

namespace name13_16 {

	class Complex
	{

	public:
		Complex();
		Complex(int real, int imaginary);

		bool operator== (const Complex& c) const
		{
			return this->real == c.real && this->imaginary == c.imaginary && this->inGoodState == c.inGoodState;
		}

	private:
		// can friend functions be private?
		friend std::ostream& operator << (std::ostream& output, const name13_16::Complex& c);
		friend std::istream& operator >> (std::istream& input, name13_16::Complex& c);
		int real;
		int imaginary;
		bool inGoodState;
		void removeSpaces(std::string& s) const;
		bool fectchNextInteger(const std::string& s, size_t& index, int& integer) const;
	};
}

