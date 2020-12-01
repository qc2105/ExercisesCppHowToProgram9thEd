#include "HourlyWorker.h"
#include <iostream>

int HourlyWorker::WorkHours = 40;

HourlyWorker::HourlyWorker(const std::string & first, const std::string & last, const std::string & ssn,
	const double WagePerHour, const unsigned NHours)
	:Employee(first, last, ssn)
{
	setWagePerHour(WagePerHour);
	setNHours(NHours);
}

void HourlyWorker::setWagePerHour(const double wage)
{
	if (wage > 0)
	{
		wagePerHour = wage;
		return;
	}
	throw std::invalid_argument("Wage must be positive\n");
}	

void HourlyWorker::setNHours(const long hours)
{
	if (hours > 0)
	{
		nHours = hours;
		return;
	}
	throw std::invalid_argument("Hours must be positive\n");
}

double HourlyWorker::earnings(void) const
{
	if (getNHours() > static_cast<unsigned>(HourlyWorker::WorkHours))
	{
		return getWagePerHour() * HourlyWorker::WorkHours + getWagePerHour() * 1.5 * (getNHours() - 40);
	}
	return getWagePerHour() * getNHours();
}

void HourlyWorker::print(void) const
{
	std::cout << "HourlyWorker: ";
	Employee::print();
	std::cout << "\nWage per hour: " << getWagePerHour() << std::endl;
	std::cout << "Worked hours: " << getNHours() << std::endl;
}
