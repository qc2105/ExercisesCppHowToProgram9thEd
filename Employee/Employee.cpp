// Employee.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Employee.h"

int main()
{
	std::string name1_first = "John";
	std::string name1_last = "Wick";

	std::string name2_first = "Bruce";
	std::string name2_last = "Lee";

	Employee* pJohn = new Employee(name1_first, name1_last, 10000);
	Employee* pBruce = new Employee(name2_first, name2_last, 12000);

	std::cout << "John's yearly salary: " << pJohn->getMonthlySalary() * 12 << std::endl;
	std::cout << "Bruce's yearly salary: " << pBruce->getMonthlySalary() * 12 << std::endl;

	pJohn->setMonthlySalary(pJohn->getMonthlySalary() * 1.10);
	pBruce->setMonthlySalary(pBruce->getMonthlySalary() * 1.10);

	std::cout << "John's yearly salary after the promotion: " << pJohn->getMonthlySalary() * 12 << std::endl;
	std::cout << "Bruce's yearly salary after the promotion: " << pBruce->getMonthlySalary() * 12 << std::endl;

	delete pJohn;
	delete pBruce;
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


Employee::Employee(std::string & firstName,
	std::string & lastName,
	int monthlySalary):
	mFirstName(firstName),
	mLastName(lastName),
	mMonthlySalary(monthlySalary)
{
	setMonthlySalary(monthlySalary);
}

Employee::~Employee()
{
}

void Employee::setFirstName(const std::string & firstName)
{
	mFirstName = firstName;
}

std::string Employee::getFirstName() const
{
	return mFirstName;
}

void Employee::setLastName(const std::string & lastName)
{
	mLastName = lastName;
}

std::string Employee::getLastName() const
{
	return mLastName;
}

void Employee::setMonthlySalary(int monthlySalary)
{
	if (monthlySalary <= 0)
	{
		mMonthlySalary = 0;
	}
	else
	{
		mMonthlySalary = monthlySalary;
	}
}

int Employee::getMonthlySalary() const
{
	return mMonthlySalary;
}
