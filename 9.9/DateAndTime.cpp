#include "DateAndTime.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <ctime>
using namespace std;

const array< int, DateAndTime::monthsPerYear + 1 > DateAndTime::daysPerMonth =
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

DateAndTime::DateAndTime(int month, int day, int year, int hour, int min, int sec)
{
	setDate(month, day, year);
	setTime(hour, min, sec);
}

DateAndTime::DateAndTime(int month, int day, int year, time_t _time_t)
{
	setDate(month, day, year);
	struct tm time_struct;
	localtime_s(&time_struct, &_time_t);
	setTime(time_struct.tm_hour, time_struct.tm_min, time_struct.tm_sec);
}

// set values of hour, minute, and second
DateAndTime &DateAndTime::setTime(int h, int m, int s) // note DateAndTime & return
{
	setHour(h);
	setMinute(m);
	setSecond(s);
	return *this; // enables cascading
} // end function setTime

// set hour value
DateAndTime &DateAndTime::setHour(int h) // note DateAndTime & return
{
	if (h >= 0 && h < 24)
		hour = h;
	else
		throw invalid_argument("hour must be 0-23");

	return *this; // enables cascading
} // end function setHour

// set minute value
DateAndTime &DateAndTime::setMinute(int m) // note DateAndTime & return
{
	if (m >= 0 && m < 60)
		minute = m;
	else
		throw invalid_argument("minute must be 0-59");

	return *this; // enables cascading
} // end function setMinute

// set second value
DateAndTime &DateAndTime::setSecond(int s) // note DateAndTime & return
{
	if (s >= 0 && s < 60)
		second = s;
	else
		throw invalid_argument("second must be 0-59");

	return *this; // enables cascading
} // end function setSecond

DateAndTime & DateAndTime::setDate(int month, int day, int year)
{
	// TODO: insert return statement here
	this->month = checkMonth(month);
	this->day = checkDay(day);
	this->year = checkYear(year);

	return *this;
}

DateAndTime & DateAndTime::tick()
{
	// TODO: insert return statement here
	if (59 == second && 59 != minute) // next minute
	{
		setMinute(++minute);
		setSecond(0);
	}
	else if (59 == minute && 59 == second && 23 != hour) // next hour
	{
		setHour(++hour);
		setMinute(0);
		setSecond(0);
	}
	else if (23 == hour && 59 == minute && 59 == second) // next day
	{
		setSecond(0);
		setMinute(0);
		setHour(0);
		nextDay();
	}
	else
	{
		setSecond(++second);
	}

	return *this;
}

// get hour value
unsigned int DateAndTime::getHour() const
{
	return hour;
} // end function getHour

// get minute value
unsigned int DateAndTime::getMinute() const
{
	return minute;
} // end function getMinute

// get second value
unsigned int DateAndTime::getSecond() const
{
	return second;
} // end function getSecond

// print DateAndTime in universal-DateAndTime format (HH:MM:SS) 
void DateAndTime::printUniversal() const
{
	cout << month << '/' << day << '/' << year << " ";
	cout << setfill('0') << setw(2) << hour << ":"
		<< setw(2) << minute << ":" << setw(2) << second << std::endl;
} // end function printUniversal

// print DateAndTime in standard-DateAndTime format (HH:MM:SS AM or PM)
void DateAndTime::printStandard() const
{
	cout << month << '/' << day << '/' << year << " ";
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
		<< ":" << setfill('0') << setw(2) << minute
		<< ":" << setw(2) << second << (hour < 12 ? " AM" : " PM") << std::endl;
} // end function printStandard

DateAndTime& DateAndTime::nextDay()
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
unsigned int DateAndTime::checkDay(int testDay) const
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

unsigned int DateAndTime::checkMonth(int testMonth) const
{
	if (testMonth > 0 && testMonth <= 12)
	{
		return testMonth;
	}

	throw invalid_argument("Invalid month");
}

unsigned int DateAndTime::checkYear(int testYear) const
{
	if (testYear != 0)
	{
		return testYear;
	}

	throw invalid_argument("Invalid year");
}