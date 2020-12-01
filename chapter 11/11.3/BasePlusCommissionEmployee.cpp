#include "BasePlusCommissionEmployee.h"
#include <stdexcept>
#include <iostream>

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string &first, const std::string &last, const std::string &ssn,
	double sales, double rate, double salary)
	// explicitly call base-class constructor
	: ce(first, last, ssn, sales, rate)
{
	setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	if (salary > 0)
	{
		baseSalary = salary;
		return;
	}
	throw std::invalid_argument("Salary must be positive.\n");
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
	return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const
{
	return ce.getCommissionRate() * ce.getGrossSales() + getBaseSalary();
}

void BasePlusCommissionEmployee::print() const
{
	std::cout << "Base salaried: " << std::endl;
	ce.print();

	std::cout << "base salary: " << getBaseSalary() << std::endl;
}
