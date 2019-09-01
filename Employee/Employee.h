#pragma once
#include <string>

class Employee
{
public:
	Employee(std::string& firstName,
		std::string& lastName,
		int monthlySalary);
	~Employee();

	void setFirstName(const std::string& firstName);
	std::string getFirstName() const;

	void setLastName(const std::string& lastName);
	std::string getLastName() const;

	void setMonthlySalary(int monthlySalary);
	int getMonthlySalary() const;

private:
	std::string mFirstName;
	std::string mLastName;
	int mMonthlySalary;
};

