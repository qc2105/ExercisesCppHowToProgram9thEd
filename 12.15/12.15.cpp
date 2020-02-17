// 12.15.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Processing Employee derived-class objects individually 
// and polymorphically using dynamic binding.
#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h" 
#include "CommissionEmployee.h"  
#include "BasePlusCommissionEmployee.h" 
#include "HourlyWorker.h"
#include "PieceWorker.h"
using namespace std;

void virtualViaPointer(const Employee * const); // prototype
void virtualViaReference(const Employee &); // prototype

int main()
{
	// set floating-point output formatting
	cout << fixed << setprecision(2);

	// create derived-class objects
	SalariedEmployee salariedEmployee(
		"John", "Smith", "111-11-1111", 800);
	CommissionEmployee commissionEmployee(
		"Sue", "Jones", "333-33-3333", 10000, .06);
	BasePlusCommissionEmployee basePlusCommissionEmployee(
		"Bob", "Lewis", "444-44-4444", 5000, .04, 300);
	HourlyWorker hourlyWorker("Blue", "Green", "555-55-5555", 100, 50);
	PieceWorker pieceWorker("John", "Wick", "666-66-6666", 1000000, 40);

	cout << "Employees processed individually using static binding:\n\n";

	// output each Employee information and earnings using static binding
	salariedEmployee.print();
	cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
	commissionEmployee.print();
	cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
	basePlusCommissionEmployee.print();
	cout << "\nearned $" << basePlusCommissionEmployee.earnings()
		<< "\n\n";
	hourlyWorker.print();
	cout << "\nearned $" << hourlyWorker.earnings()
		<< "\n\n";
	pieceWorker.print();
	cout << "\nearned $" << pieceWorker.earnings()
		<< "\n\n";
	
	// create vector of three base-class pointers
	vector < Employee * > employees(5);

	// initialize vector with Employees
	employees[0] = &salariedEmployee;
	employees[1] = &commissionEmployee;
	employees[2] = &basePlusCommissionEmployee;
	employees[3] = &hourlyWorker;
	employees[4] = &pieceWorker;
	

	cout << "Employees processed polymorphically via dynamic binding:\n\n";

	// call virtualViaPointer to print each Employee's information
	// and earnings using dynamic binding
	cout << "Virtual function calls made off base-class pointers:\n\n";

	for (const Employee *employeePtr : employees)
		virtualViaPointer(employeePtr);

	// call virtualViaReference to print each Employee's information 
	// and earnings using dynamic binding
	cout << "Virtual function calls made off base-class references:\n\n";

	for (const Employee *employeePtr : employees)
		virtualViaReference(*employeePtr); // note dereferencing

	for (size_t i = 0; i < employees.size(); ++i)
	{
		employees.at(i) = nullptr;
	}

	return 0;
} // end main

// call Employee virtual functions print and earnings off a 
// base-class pointer using dynamic binding
void virtualViaPointer(const Employee * const baseClassPtr)
{
	baseClassPtr->print();
	cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
} // end function virtualViaPointer

// call Employee virtual functions print and earnings off a 
// base-class reference using dynamic binding
void virtualViaReference(const Employee &baseClassRef)
{
	baseClassRef.print();
	cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
} // end function virtualViaReference

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