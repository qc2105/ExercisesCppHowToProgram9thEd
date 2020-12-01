// Fig. 10.15: Complex.cpp
// Complex class member-function definitions.
#include <iostream>
#include "Complex.h" // Complex class definition
using namespace std;

// Constructor
Complex::Complex( double realPart, double imaginaryPart ) 
   : real( realPart ),
   imaginary( imaginaryPart ) 
{ 
   // empty body
} // end Complex constructor

// addition operator
Complex Complex::operator+( const Complex &operand2 ) const
{
   return Complex( real + operand2.real, 
      imaginary + operand2.imaginary );
} // end function operator+

// subtraction operator
Complex Complex::operator-( const Complex &operand2 ) const
{
   return Complex( real - operand2.real, 
      imaginary - operand2.imaginary );
} // end function operator-

// display a Complex object in the form: (a, b)
void Complex::print() const
{ 
   cout << '(' << real << ", " << imaginary << ')';
} // end function print

Complex  Complex::operator*(const Complex & right) const
{
	// TODO: insert return statement here
	double a = this->getReal();
	double b = this->getImaginary();
	double c = right.getReal();
	double d = right.getImaginary();

	Complex num;

	num.setReal(a * c - b * d);
	num.setImaginary(a * d + b * c);
	
	return num;
}

bool Complex::operator==(const Complex &right) const
{
	if (getReal() != right.getReal() || getImaginary() != right.getImaginary())
	{
		return false;
	}
	return true;
}

std::ostream & operator<< (std::ostream & out, const Complex &right)
{
	out << '(' << right.getReal() << ", " << right.getImaginary() << ')' << std::endl;
	return out;
}

std::istream & operator>> (std::istream &in, Complex &right)
{
	double real, imaginary;
	in >> real >> imaginary;
	right.setReal(real);
	right.setImaginary(imaginary);

	return in;
}

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
