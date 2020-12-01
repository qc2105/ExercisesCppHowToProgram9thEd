// Fig. 9.5: Time.cpp
// Member-function definitions for class Time.
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

// Time constructor initializes each data member 
Time::Time(int hour, int minute, int second)
{
	setTime(hour, minute, second); // validate and set time
} // end Time constructor

// set new Time value using universal time
Time::error_status Time::setTime(int h, int m, int s)
{
	if (eOk != setHour(h))
	{
		return eInvalidHour;
	}
	if (eOk != setMinute(m))
	{
		return eInvalidMinute;
	}
	if (eOk != setSecond(s))
	{
		return eInvalidSecond;
	}

	return eOk;
} // end function setTime

// set hour value
Time::error_status Time::setHour(int h)
{
	if (h >= 0 && h < 24)
	{
		hour = h;
		return eOk;
	}
	else
	{
		return eInvalidHour;
	}
} // end function setHour

// set minute value
Time::error_status Time::setMinute(int m)
{
	if (m >= 0 && m < 60)
	{
		minute = m;
		return eOk;
	}
	else
	{
		return eInvalidMinute;
	}
} // end function setMinute

// set second value
Time::error_status Time::setSecond(int s)
{
	if (s >= 0 && s < 60)
	{
		second = s;
		return eOk;
	}
	else
	{
		return eInvalidSecond;
	}
} // end function setSecond

// return hour value
unsigned int Time::getHour() const
{
	return hour;
} // end function getHour

// return minute value
unsigned int Time::getMinute() const
{
	return minute;
} // end function getMinute

// return second value
unsigned int Time::getSecond() const
{
	return second;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const
{
	cout << setfill('0') << setw(2) << getHour() << ":"
		<< setw(2) << getMinute() << ":" << setw(2) << getSecond();
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() const
{
	cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
		<< ":" << setfill('0') << setw(2) << getMinute()
		<< ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
} // end function printStandard

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
