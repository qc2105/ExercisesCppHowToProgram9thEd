#pragma once
#include <array>
#include <ctime>

class DateAndTime
{
public:
	explicit DateAndTime(int month = 1, int day = 1, int year = 1900, int hour = 0, int min = 0, int sec = 0); // default constructor
	DateAndTime(int month, int day, int year, time_t _time_t);

	static const unsigned int monthsPerYear = 12; // months in a year
	static const std::array< int, monthsPerYear + 1 > daysPerMonth;

	// set functions (the Time & return types enable cascading)
	DateAndTime &setTime(int, int, int); // set hour, minute, second
	DateAndTime &setHour(int); // set hour
	DateAndTime &setMinute(int); // set minute
	DateAndTime &setSecond(int); // set second

	DateAndTime &setDate(int month, int day, int year);

	DateAndTime &tick();

	// get functions (normally declared const)
	unsigned int getHour() const; // return hour
	unsigned int getMinute() const; // return minute
	unsigned int getSecond() const; // return second
	// print functions (normally declared const)
	void printUniversal() const; // print universal time
	void printStandard() const; // print standard time

	DateAndTime& nextDay();
private:
	unsigned int hour; // 0 - 23 (24-hour clock format)
	unsigned int minute; // 0 - 59
	unsigned int second; // 0 - 59

	unsigned int month; // 1-12 (January-December)
	unsigned int day; // 1-31 based on month
	unsigned int year; // any year

	// utility function to check if day is proper for month and year
	unsigned int checkDay(int) const;
	unsigned int checkMonth(int) const;
	unsigned int checkYear(int) const;
};

