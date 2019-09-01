// Date.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Date.h"

int main()
{
	Date birthDay(01, 01, 0000);
	Date theEnd(32, 13, 9999);

	birthDay.displayDate();
	theEnd.displayDate();
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


Date::Date(int day, int month, int year):
	mDay(day),
	mMonth(month),
	mYear(year)
{
	//validation 
	setMonth(month);
}


Date::~Date()
{
}

void Date::setDay(const int day)
{
	mDay = day;
}

int Date::getDay() const
{
	return mDay;
}

void Date::setMonth(const int month)
{
	if (1 <= month && month <= 12)
	{
		mMonth = month;
	}
	else
	{
		mMonth = 1;
	}
}

int Date::getMonth() const
{
	return mMonth;
}

void Date::setYear(const int year)
{
	mYear = year;
}

int Date::getYear() const
{
	return mYear;
}

void Date::displayDate() const
{
	std::cout << getMonth() << "/" << getDay() << "/" << getYear() << std::endl;
}
