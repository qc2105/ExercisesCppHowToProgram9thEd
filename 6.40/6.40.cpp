// Fig. 6.28: fig06_28.cpp
// Recursive function factorial.
#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

unsigned long factorial(unsigned long); // function prototype
int n = 0;
unsigned long result = 0;

int main()
{
	// calculate the factorials of 0 through 10
	for (unsigned int counter = 0; counter <= 10; ++counter)
	{
		cout << setw(2) << "\n" << counter << "! = " << factorial(counter)
			<< endl;
		n = 0;
		std::cout << "---------------" << std::endl;
	}
		
} // end main

// recursive definition of function factorial
unsigned long factorial(unsigned long number)
{
	n++;
	std::cout << "\n" << std::setw(n) << "(" << number << "! = " << number << " * " << (number == 0 ? 1 : number-1) << "!), ?= " << (number == 0 ? 1 : number - 1) << "!";
	
	if (number <= 1) // test for base case
	{
		return 1; // base cases: 0! = 1 and 1! = 1
	}
	else 
	{// recursion step
		result = number * factorial(number - 1);
		return result;
	}
} // end function factorial


/*************************************************************************
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
*************************************************************************/
