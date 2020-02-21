// Fig. 10.3: PhoneNumber.h
// PhoneNumber class definition
#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <string>

class PhoneNumber
{
   friend std::ostream &operator<<( std::ostream &, const PhoneNumber & );
   friend std::istream &operator>>( std::istream &, PhoneNumber & );
private:
   std::string areaCode; // 3-digit area code 
   std::string exchange; // 3-digit exchange 
   std::string line; // 4-digit line 
   bool areDigits(const std::string &s);
   bool isValidAreaExchangeCode(const std::string &s);
   bool isLengthCorrect(const std::string &s, const int expectLength);
   bool isValidOldAreaCode(const std::string &s);
}; // end class PhoneNumber

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
