// Fig. 9.18: Date.cpp
// Date class member-function definitions.
#include "pch.h"
#include <array>
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>

#include <sstream>
#include <vector>

#include "Date.h" // include Date class definition
using namespace std;

const std::array<int, Date::monthsPerYear+1> Date::daysPerMonth =
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

const std::array<std::string, Date::monthsPerYear + 1> Date::monthNames =
{
	"unkown",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date( int mn, int dy, int yr )
{
   if ( mn > 0 && mn <= monthsPerYear ) // validate the month
      month = mn;
   else 
      throw invalid_argument( "month must be 1-12" );

   year = yr; // could validate yr
   day = checkDay( dy ); // validate the day

   // output Date object to show when its constructor is called
   cout << "Date object constructor for date ";
   print();                   
   cout << endl;
} // end Date constructor

Date::Date(std::string dateString)
	:month(0),
	day(0),
	year(0)
{
	if (dateString.find(",") != std::string::npos)	// June 14, 1992 
	{
		size_t pos_first_space = dateString.find(" ");
		if (pos_first_space == std::string::npos)
		{
			throw("Invalid date string.");
		}
		else
		{
			try 
			{
				std::string monthString = dateString.substr(0, pos_first_space);
				month = getMonthFromString(monthString);
				size_t pos_comma = dateString.find(",");
				std::string dayString = dateString.substr(pos_first_space + 1, pos_comma - pos_first_space - 1);
				day = std::stoi(dayString);
				std::string yearString = dateString.substr(pos_comma + 2, dateString.length() - pos_comma);
				year = std::stoi(yearString);
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			
		}
	}
	else if (dateString.find(" ") != std::string::npos) // DDD YYYY
	{
		size_t pos_space = dateString.find(" ");
		std::string dayOfYearString = dateString.substr(0, pos_space);
		int DDD = std::stoi(dayOfYearString);
		std::string yearString = dateString.substr(pos_space + 1, dateString.length() - pos_space - 1);
		year = std::stoi(yearString);

		month = 0;
		for (int i = 0; i <= daysPerMonth.size() - 1; i++)
		{
			if (DDD <= daysPerMonth[i])
			{
				month = i;
				day = DDD;
				break;
			}
			DDD -= daysPerMonth[i];
		}
	}
	else if (dateString.find("/") != std::string::npos) //
	{
		std::vector<std::string> strings;
		std::istringstream f(dateString);
		string s;
		while (getline(f, s, '/'))
		{
			strings.push_back(s);
		}

		std::string monthString = strings.at(0);
		month = std::stoi(monthString);
		std::string dayString = strings.at(1);
		day = std::stoi(dayString);
		std::string yearString = strings.at(2);
		year = std::stoi(yearString);
	}
	else
	{
		throw("Invalid input string");
	}

	if (month > 0 && month <= monthsPerYear) // validate the month
		month = month;
	else
		throw invalid_argument("month must be 1-12");

	day = checkDay(day); // validate the day

	// output Date object to show when its constructor is called
	cout << "Date object constructor for date ";
	print();
	cout << endl;
}

// print Date object in form month/day/year
void Date::print() const
{
   cout << month << '/' << day << '/' << year; 
} // end function print

void Date::printDDD_YYYY() const
{
	int ddd = 0; 
	for (unsigned int i = 1; i <= month-1; i++)
	{
		ddd += daysPerMonth[i];
	}
	ddd += day;

	std::setfill('0');
	std::cout << std::setw(3) << ddd << " " << year << std::endl;
}

void Date::printMM_DD_YY() const
{
	int YY = year % 100;
	int MM = month;
	int DD = day;

	std::cout << MM << "/" << DD << "/" << YY << std::endl;
}

void Date::printEn_US() const
{
	std::string monthString;
	switch (month)
	{
	case 1:
		monthString = "January";
		break;
	case 2:
		monthString = "February";
		break;
	case 3:
		monthString = "March";
		break;
	case 4:
		monthString = "April";
		break;
	case 5:
		monthString = "May";
		break;
	case 6:
		monthString = "June";
		break;
	case 7:
		monthString = "July";
		break;
	case 8:
		monthString = "August";
		break;
	case 9:
		monthString = "September";
		break;
	case 10:
		monthString = "October";
		break;
	case 11:
		monthString = "November";
		break;
	case 12:
		monthString = "December";
		break;
	default:
		monthString = "Unkown";
		break;
	}

	std::cout << monthString << " " << day << ", " << year << std::endl;
}

// output Date object to show when its destructor is called
Date::~Date()
{ 
   cout << "Date object destructor for date ";
   print();
   cout << endl;
} // end ~Date destructor

int Date::getMonthFromString(std::string monthString) const
{
	for (int i = 0; i < static_cast<int>(monthNames.size()); i++)
	{
		if (monthString == monthNames.at(i))
		{
			return i;
		}
	}
	return 1;
}

// utility function to confirm proper day value based on 
// month and year; handles leap years, too
unsigned int Date::checkDay( int testDay ) const
{
   // determine whether testDay is valid for specified month
   if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
      return testDay;

   // February 29 check for leap year 
   if ( month == 2 && testDay == 29 && ( year % 400 == 0 || 
      ( year % 4 == 0 && year % 100 != 0 ) ) )
      return testDay;

   throw invalid_argument( "Invalid day for current month and year" );
} // end function checkDay

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
