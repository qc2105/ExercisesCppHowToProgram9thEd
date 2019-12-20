// Fig. 9.25: Time.cpp 
// Time class member-function definitions.
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <ctime>
#include "Time.h" // Time class definition
using namespace std;

// constructor function to initialize private data;
// calls member function setTime to set variables;
// default values are 0 (see class definition)
Time::Time( int hr, int min, int sec ) 
{ 
   setTime( hr, min, sec ); 
} // end Time constructor

Time::Time(time_t time_t_value)
{
	struct tm time_struct;
	localtime_s(&time_struct, &time_t_value);
	setTime(time_struct.tm_hour, time_struct.tm_min, time_struct.tm_sec);
}

// set values of hour, minute, and second
Time &Time::setTime( int h, int m, int s ) // note Time & return
{
   setHour( h );
   setMinute( m );
   setSecond( s ); 
   return *this; // enables cascading
} // end function setTime

// set hour value
Time &Time::setHour( int h ) // note Time & return
{
   if ( h >= 0 && h < 24 )
      hour = h;
   else
      throw invalid_argument( "hour must be 0-23" );

   return *this; // enables cascading
} // end function setHour

// set minute value
Time &Time::setMinute( int m ) // note Time & return
{
   if ( m >= 0 && m < 60 )
      minute = m; 
   else
      throw invalid_argument( "minute must be 0-59" );

   return *this; // enables cascading
} // end function setMinute

// set second value
Time &Time::setSecond( int s ) // note Time & return
{
   if ( s >= 0 && s < 60 )
      second = s; 
   else
      throw invalid_argument( "second must be 0-59" );

   return *this; // enables cascading
} // end function setSecond

Time & Time::tick()
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
	}
	else
	{
		setSecond(++second);
	}

	return *this;
}

// get hour value
unsigned int Time::getHour() const 
{ 
   return hour; 
} // end function getHour

// get minute value
unsigned int Time::getMinute() const 
{ 
   return minute; 
} // end function getMinute

// get second value
unsigned int Time::getSecond() const 
{ 
   return second; 
} // end function getSecond

// print Time in universal-time format (HH:MM:SS) 
void Time::printUniversal() const
{
   cout << setfill( '0' ) << setw( 2 ) << hour << ":"
      << setw( 2 ) << minute << ":" << setw( 2 ) << second;
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() const
{
   cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 )
      << ":" << setfill( '0' ) << setw( 2 ) << minute
      << ":" << setw( 2 ) << second << ( hour < 12 ? " AM" : " PM" );
} // end function printStandard

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
