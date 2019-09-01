#pragma once
#include <string>
#include <Windows.h>


class HeartRates
{
public:
	HeartRates( std::string& firstName,
				std::string& lastName,
				int month,
				int day,
				int year);

	~HeartRates();

	void setFirstName(const std::string& firstName);
	std::string getFirstName() const;

	void setLastName(const std::string& lastName);
	std::string getLastName() const;

	int setMonth(const int month);
	int getMonth() const;

	int setDay(const int day);
	int getDay() const;

	int setYear(const int year);
	int getYear() const;

	int getAge() const;

	int getMaximumHeartRate() const;
	int getTargetHearRate() const;

private:
	std::string mFirstName;
	std::string mLastName;
	int mMonth;
	int mDay;
	int mYear;
};

