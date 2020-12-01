// Fig. 9.5: Time.cpp
// Member-function definitions for class Time.
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

// Time constructor initializes each data member 
Time::Time(int hour, int minute, int second)
	:secondsSinceMidNight(0)
{
	setTime(hour, minute, second); // validate and set time
} // end Time constructor

// set new Time value using universal time
void Time::setTime(int h, int m, int s)
{
	setHour(h); // set private field hour
	setMinute(m); // set private field minute
	setSecond(s); // set private field second
} // end function setTime

// set hour value
void Time::setHour(int h)
{
	if (h >= 0 && h < 24)
		secondsSinceMidNight += h * 3600;
	else
		throw invalid_argument("hour must be 0-23");
} // end function setHour

// set minute value
void Time::setMinute(int m)
{
	if (m >= 0 && m < 60)
		secondsSinceMidNight += m * 60;
	else
		throw invalid_argument("minute must be 0-59");
} // end function setMinute

// set second value
void Time::setSecond(int s)
{
	if (s >= 0 && s < 60)
		secondsSinceMidNight += s;
	else
		throw invalid_argument("second must be 0-59");
} // end function setSecond

// return hour value
unsigned int Time::getHour() const
{
	return secondsSinceMidNight / 3600;
} // end function getHour

// return minute value
unsigned int Time::getMinute() const
{
	return secondsSinceMidNight % 3600 / 60;
} // end function getMinute

// return second value
unsigned int Time::getSecond() const
{
	return secondsSinceMidNight % 3600 % 60;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const
{
	cout << setfill('0') << setw(2) << getHour() << ":"
		<< setw(2) << getMinute() << ":" << setw(2) << getSecond() << std::endl;
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() const
{
	cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
		<< ":" << setfill('0') << setw(2) << getMinute()
		<< ":" << setw(2) << getSecond() << (getHour() < 12 ? " AM" : " PM") << std::endl;
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
