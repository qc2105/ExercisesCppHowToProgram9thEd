// 13.14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Fig. 10.5: fig10_05.cpp
// Demonstrating class PhoneNumber's overloaded stream insertion 
// and stream extraction operators.
#include <iostream>
#include "PhoneNumber.h"
using namespace std;

int main()
{
	PhoneNumber phone; // create object phone

	cout << "Enter phone number in the form (213) 456-7890:" << endl;

	// cin >> phone invokes operator>> by implicitly issuing
	// the global function call operator>>( cin, phone )
	cin.clear();
	if (!(cin >> phone))
	{
		cout << "Wrong format, the right format is like: (213) 456-7890";
		return -1;
	}
	cout << "The phone number entered was: ";

	// cout << phone invokes operator<< by implicitly issuing 
	// the global function call operator<<( cout, phone )
	cout << phone << endl;

	return 0;
} // end main

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
