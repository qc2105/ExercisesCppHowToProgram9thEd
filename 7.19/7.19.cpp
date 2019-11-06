// Fig. 7.25: fig07_25.cpp
// Demonstrating C++ Standard Library class template array.
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <stdexcept> // for out_of_range exception class
using namespace std;

const int arraySize = 3;

void outputVector( const array< int, arraySize> & ); // display the array
void inputVector( array< int, arraySize> & ); // input values into the array

int main()
{
	array< int, arraySize> integers1 = { 0 }; // 7-element array< int >
	array< int, arraySize> integers2 = { 0 }; // 10-element array< int >
 
   // print integers1 size and contents
   cout << "Size of array integers1 is " << integers1.size()
      << "\nvector after initialization:" << endl;
   outputVector( integers1 );

   // print integers2 size and contents
   cout << "\nSize of array integers2 is " << integers2.size()
      << "\nvector after initialization:" << endl;
   outputVector( integers2 );

   // input and print integers1 and integers2
   cout << "\nEnter " << arraySize * 2 << " integers:" << endl;
   inputVector( integers1 );
   inputVector( integers2 );
    
   cout << "\nAfter input, the vectors contain:\n"
      << "integers1:" << endl;
   outputVector( integers1 );
   cout << "integers2:" << endl;
   outputVector( integers2 );

   // use inequality (!=) operator with array objects
   cout << "\nEvaluating: integers1 != integers2" << endl;

   if ( integers1 != integers2 )
      cout << "integers1 and integers2 are not equal" << endl;

   // create array integers3 using integers1 as an
   // initializer; print size and contents
   array< int , arraySize> integers3( integers1 ); // copy constructor

   cout << "\nSize of array integers3 is " << integers3.size()
      << "\nvector after initialization:" << endl;
   outputVector( integers3 );

   // use assignment (=) operator with array objects
   cout << "\nAssigning integers2 to integers1:" << endl;
   integers1 = integers2; // assign integers2 to integers1

   cout << "integers1:" << endl;
   outputVector( integers1 );
   cout << "integers2:" << endl;
   outputVector( integers2 );

   // use equality (==) operator with array objects
   cout << "\nEvaluating: integers1 == integers2" << endl;

   if ( integers1 == integers2 )
      cout << "integers1 and integers2 are equal" << endl;

   // use square brackets to use the value at location arraySize - 1 as an rvalue
   cout << "\nintegers1[" << arraySize -1 << "] is " << integers1[ arraySize-1 ];

   // use square brackets to create lvalue
   cout << "\n\nAssigning 1000 to integers1["<< arraySize -1 << "]" << endl;
   integers1[ arraySize - 1 ] = 1000;
   cout << "integers1:" << endl;
   outputVector( integers1 );

   // attempt to use out-of-range subscript
   try
   {
      cout << "\nAttempt to display integers1.at( 15 )" << endl;
      cout << integers1.at( 15 ) << endl; // ERROR: out of range
   } // end try
   catch ( out_of_range &ex )
   {
      cerr << "An exception occurred: " << ex.what() << endl;
   } // end catch

   cout << "\nCurrent integers3 size is: " << integers3.size() << endl;
   integers3.at(arraySize - 1) = 1000; // add 1000 to the end of the array
   cout << "New integers3 size is: " << integers3.size() << endl;
   cout << "integers3 now contains: ";
   outputVector( integers3 );
} // end main

// output array contents
void outputVector( const array< int, arraySize > &items )
{
   for ( int item : items )
      cout << item << " ";

   cout << endl;
} // end function outputVector

// input array contents
void inputVector( array< int, arraySize > &items )
{
	for (int i = 0; i < arraySize; i++)
	{
		cin >> items[i];
	}
} // end function inputVector

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
