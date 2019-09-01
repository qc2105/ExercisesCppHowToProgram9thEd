#include "utils.h"
#include "pch.h"

bool isLeapYear(const int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 3200 != 0) || year % 172800 == 0)
		return true;
	else
		return false;
}
