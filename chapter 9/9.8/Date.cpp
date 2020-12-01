// Fig. 9.18: Date.cpp
// Date class member-function definitions.
#include <array>
#include <iostream>
#include <stdexcept>
#include "Date.h" // include Date class definition
using namespace std;

const array< int, Date::monthsPerYear + 1 > Date::daysPerMonth =
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date(int mn, int dy, int yr)
{
	month = checkMonth(mn);
	year = checkYear(yr);
	day = checkDay(dy); // validate the day

} // end Date constructor

// print Date object in form month/day/year
void Date::print() const
{
	cout << month << '/' << day << '/' << year << std::endl;
} // end function print

// output Date object to show when its destructor is called
Date::~Date()
{
} // end ~Date destructor

Date& Date::nextDay()
{
	if (12 == month && 31 == day) // next year
	{
		year++;
		month = 1;
		day = 1;
	}
	else if (day == daysPerMonth[month]) // next month
	{
		day = 1;
		month++;
	}
	else
	{
		day++;
	}
	
	return *this;
}

// utility function to confirm proper day value based on 
// month and year; handles leap years, too
unsigned int Date::checkDay(int testDay) const
{
	// determine whether testDay is valid for specified month
	if (testDay > 0 && testDay <= daysPerMonth[month])
		return testDay;

	// February 29 check for leap year 
	if (month == 2 && testDay == 29 && (year % 400 == 0 ||
		(year % 4 == 0 && year % 100 != 0)))
		return testDay;

	throw invalid_argument("Invalid day for current month and year");
} // end function checkDay

unsigned int Date::checkMonth(int testMonth) const
{
	if (testMonth > 0 && testMonth <= 12)
	{
		return testMonth;
	}

	throw invalid_argument("Invalid month");
}

unsigned int Date::checkYear(int testYear) const
{
	if (testYear != 0)
	{
		return testYear;
	}

	throw invalid_argument("Invalid year");
}

/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
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
