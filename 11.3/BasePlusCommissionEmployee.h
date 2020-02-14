#pragma once
#include "CommissionEmployee.h"
#include <string>

class BasePlusCommissionEmployee
{
public:
	BasePlusCommissionEmployee(const std::string &first, const std::string &last, const std::string &ssn,
		double sales, double rate, double salary);

	void setBaseSalary(double); // set base salary
	double getBaseSalary() const; // return base salary

	double earnings() const; // calculate earnings
	void print() const; // print BasePlusCommissionEmployee object

	CommissionEmployee ce;
private:
	double baseSalary; // base salary
};

