// Fig. 10.14: Complex.h
// Complex class definition.
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex
{
public:
   explicit Complex( double = 0.0, double = 0.0 ); // constructor
   Complex operator+( const Complex & ) const; // addition
   Complex operator-( const Complex & ) const; // subtraction
   void print() const; // output

   Complex operator* (const Complex &right) const;

   bool operator== (const Complex &right) const;

   bool operator!= (const Complex &right) const
   {
	   return !operator==(right);
   }

   double getReal(void) const
   {
	   return real;
   }
   double getImaginary(void) const
   {
	   return imaginary;
   }
   
   void setReal(double real)
   {
	   this->real = real;
   }

   void setImaginary(double imaginary)
   {
	   this->imaginary = imaginary;
   }

private:
   double real; // real part
   double imaginary; // imaginary part
}; // end class Complex

#endif

std::ostream & operator<< (std::ostream &out, const Complex &right);
std::istream & operator>> (std::istream &in, Complex &right);

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
