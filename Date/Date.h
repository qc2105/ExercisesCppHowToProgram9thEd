#pragma once
class Date
{
public:
	Date(int day, int monty, int year);
	~Date();

	void setDay(const int day);
	int getDay() const;

	void setMonth(const int month);
	int getMonth() const;

	void setYear(const int year);
	int getYear() const;

	void displayDate() const;
private:
	int mDay;
	int mMonth;
	int mYear;
};

