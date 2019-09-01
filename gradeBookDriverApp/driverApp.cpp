// gradeBookDriverApp.cpp : main entry
//

#include "pch.h"
#include <iostream>
using namespace std;

#include "../gradebook/GradeBook.h"
#include "../account/Account.h"

void seperator()
{
	cout << "----------------------------------------------" << endl;
}

int main()
{
	GradeBook book1("Math", "Mrs. Liu");
	book1.displayMessage();
	
	seperator();

	GradeBook book2;
	book2.setCourseName("English");
	book2.setInstructorName("Miss Liu");
	book2.displayMessage();

	for (int i = 0; i < 2; i++)
	{
		seperator();
	}

	Account acc(99999);
	acc.credit(10000);
	acc.debit(500);
	acc.displayBalance();

	seperator();

	Account acd(-100);
	acd.credit(888888);
	acd.debit(999999999);
	acd.displayBalance();

	return 0;
}