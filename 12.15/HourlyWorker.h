#pragma once
#include "Employee.h"
class HourlyWorker :
	public Employee
{
public:
	static int WorkHours;
	HourlyWorker(const std::string &first, const std::string &last, const std::string &ssn, 
		const double WagePerHour, const unsigned NHours);
	virtual ~HourlyWorker() {};

	void setWagePerHour(const double wage);
	double getWagePerHour(void) const
	{
		return wagePerHour;
	}

	void setNHours(const long hours);
	unsigned getNHours(void) const
	{
		return nHours;
	}

	virtual double earnings(void) const;
	virtual void print(void) const;

private:
	double wagePerHour;
	unsigned nHours;
};

