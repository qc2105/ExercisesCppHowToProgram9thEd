// Fig. 10.4: PhoneNumber.cpp
// Overloaded stream insertion and stream extraction operators
// for class PhoneNumber.
#include <iomanip>
#include <cctype>
#include "PhoneNumber.h"
using namespace std;

// overloaded stream insertion operator; cannot be 
// a member function if we would like to invoke it with
// cout << somePhoneNumber;
ostream &operator<<( ostream &output, const PhoneNumber &number )
{
   output << "(" << number.areaCode << ") "
      << number.exchange << "-" << number.line;
   return output; // enables cout << a << b << c;
} // end function operator<< 

// overloaded stream extraction operator; cannot be 
// a member function if we would like to invoke it with
// cin >> somePhoneNumber;
istream &operator>>( istream &input, PhoneNumber &number )
{
	char *inputCString = new char[20]();
	input.getline(inputCString, 20);
	std::string inputString(inputCString);
	if (inputString.length() != 14)
	{
		input.clear(std::ios_base::failbit);
	}
	std::string areaCode, exchange, line;
   
	areaCode = inputString.substr(1, 3);
	if (!number.areDigits(areaCode) || !number.isValidAreaExchangeCode(areaCode) || !number.isValidOldAreaCode(areaCode))
	{
		input.clear(std::ios_base::failbit);
	}
	exchange = inputString.substr(6, 3);
	if (!number.areDigits(exchange) || !number.isValidAreaExchangeCode(exchange))
	{
		input.clear(std::ios_base::failbit);
	}
	
	line = inputString.substr(10, 4);
	if (!number.areDigits(line))
	{
		input.clear(std::ios_base::failbit);
	}

	number.areaCode = areaCode;
	number.exchange = exchange;
	number.line = line;

	return input; // enables cin >> a >> b >> c;
} // end function operator>> 

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

bool PhoneNumber::areDigits(const std::string & s) const
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (!isdigit(s.at(i)))
		{
			return false;
		}
	}
	return true;
}

bool PhoneNumber::isValidAreaExchangeCode(const std::string & s) const
{
	if (s.empty())
	{
		return false;
	}
	return s.at(0) != '0' && s.at(0) != '1';
}

bool PhoneNumber::isLengthCorrect(const std::string & s, const int expectLength) const
{
	return s.length() == expectLength;
}

bool PhoneNumber::isValidOldAreaCode(const std::string & s) const
{
	return isLengthCorrect(s, 3) && (s.at(1) == '0' || s.at(1) == '1');
}
