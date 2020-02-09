// Fig. 10.17: Hugeint.h 
// HugeInt class definition.
#ifndef HUGEINT_H
#define HUGEINT_H

#include <array>
#include <iostream>
#include <string>

class HugeInt
{
   friend std::ostream &operator<<( std::ostream &, const HugeInt & );
public:
   static const int digits = 30; // maximum digits in a HugeInt

   HugeInt( long = 0 ); // conversion/default constructor
   HugeInt( const std::string & ); // conversion constructor

   // addition operator; HugeInt + HugeInt
   HugeInt operator+( const HugeInt & ) const;

   // addition operator; HugeInt + int
   HugeInt operator+( int ) const;            

   // addition operator; 
   // HugeInt + string that represents large integer value
   HugeInt operator+( const std::string & ) const;  

   HugeInt operator*(const HugeInt &) const;
   HugeInt operator*(int) const;
   HugeInt operator*(const std::string &) const;

   HugeInt operator/(const HugeInt &) const;
   HugeInt operator/(int) const;
   HugeInt operator/(const std::string &) const;

   bool operator==(const HugeInt &) const;
   bool operator!=(const HugeInt &right) const
   {
	   return !operator==(right);
   }
   bool operator> (const HugeInt &right) const;
   bool operator>= (const HugeInt &right) const;
   bool operator< (const HugeInt &right) const;
   bool operator<= (const HugeInt &right) const;

private:
   std::array< short, digits > integer;
}; // end class HugetInt

#endif


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
