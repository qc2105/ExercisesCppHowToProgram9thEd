#include "pch.h"
#include "HeartRates.h"
#include "utils.h"

HeartRates::HeartRates(std::string & firstName, std::string & lastName, int month, int day, int year) :
	mFirstName(firstName),
	mLastName(lastName),
	mMonth(month),
	mDay(day),
	mYear(year)
{
	//validation
	setMonth(month);
	setDay(day);
	setYear(year);
}

HeartRates::~HeartRates()
{
}

void HeartRates::setFirstName(const std::string & firstName)
{
	mFirstName = firstName;
}

std::string HeartRates::getFirstName() const
{
	return mFirstName;
}

void HeartRates::setLastName(const std::string & lastName)
{
	mLastName = lastName;
}

std::string HeartRates::getLastName() const
{
	return mLastName;
}

int HeartRates::setMonth(const int month)
{
	if (month < 1 || month > 12)
	{
		mMonth = 1;
		return -1;
	}
	else
	{
		mMonth = month;
		return 0;
	}
}

int HeartRates::getMonth() const
{
	return mMonth;
}

int HeartRates::setDay(const int day)
{
	if (day < 1)
	{
		mDay = 1;
		return -1;
	}
	switch (mMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day > 31)
		{
			mDay = 31;
			return -1;
		}
		else
		{
			mDay = day;
			break;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		if (day > 30)
		{
			mDay = 30;
			return -1;
		}
		else
		{
			mDay = day;
			break;
		}
	case 2:
		if (isLeapYear(mYear))
		{
			if (mDay > 29)
			{
				mDay = 29;
				return -1;
			}
			else
			{
				mDay = day;
			}
		}
		else
		{
			if (mDay > 28)
			{
				mDay = 28;
				return -1;
			}
			else
			{
				mDay = day;
			}
		}
		break;
	default:
		break;
	}

	return 0;
}

int HeartRates::getDay() const
{
	return mDay;
}

int HeartRates::setYear(const int year)
{
	if (year < 0)
	{
		mYear = 0;
		return -1;
	}
	else
	{
		mYear = year;
		return 0;
	}
}

int HeartRates::getYear() const
{
	return mYear;
}

int HeartRates::getAge() const
{
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	int currentYear = str_t.wYear;
	int currentDay = str_t.wDay;
	int currentMonth = str_t.wMonth;
	if (currentMonth < getMonth())
	{
		return currentYear - 1 - mYear;
	}
	else if (currentMonth == getMonth())
	{
		if (currentDay < mDay)
		{
			return currentYear - 1 - mYear;
		}
		else
		{
			return currentYear - mYear;
		}
	}
	else
	{
		return currentYear - mYear;
	}
}

int HeartRates::getMaximumHeartRate() const
{
	return 220 - getAge();
}

int HeartRates::getTargetHearRate() const
{
	return getMaximumHeartRate() / 2;
}
