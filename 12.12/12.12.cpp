// 12.12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BasePlusCommissionEmployee.h"
#include "CommissionEmployee.h"
#include "Date.h"
#include "Employee.h"
#include "SalariedEmployee.h"
#include <vector>
#include <string>

int main()
{
    std::cout << "Hello World!\n";

	std::vector<Employee *> employeePtrs(3, nullptr);
	std::vector<std::string> firstNames{ "Chuan", "Jia", "Rong" };
	std::vector<std::string> lastNames{ "Qin", "Qin", "Qin" };
	std::vector<std::string> socialSecurityNumbers{ "111-1111-1111", "222-2222-2222", "333-3333-3333" };
	double salary = 8000;
	double sales = 10000;
	double rate = 0.1;
	double baseSalary = 2000;
	int currentMonth = 5;

	BasePlusCommissionEmployee *basePlusPtr = new BasePlusCommissionEmployee(firstNames[2], lastNames[2], socialSecurityNumbers[2],
		sales, rate * 3, salary * 2);
	basePlusPtr->setBirthDate(5, 4, 2022);
	CommissionEmployee *comPtr = new CommissionEmployee(firstNames[1], lastNames[1], socialSecurityNumbers[1], sales * 10, rate);
	SalariedEmployee *salariedPtr = new SalariedEmployee(firstNames[0], lastNames[0], socialSecurityNumbers[0], salary * 2);

	employeePtrs[0] = basePlusPtr;
	employeePtrs[1] = comPtr;
	employeePtrs[2] = salariedPtr;

	for (Employee *ePtr : employeePtrs)
	{
		double bonus = 0;
		if (ePtr->getBirthDate().getMonth() == currentMonth)
		{
			bonus = 100;
		}
		std::cout << typeid(*ePtr).name() << ": " << ePtr->getBirthDate() << "\n";
		bonus == 100 ? (std::cout << "Birthday bonus: " << bonus << '\n') : ( std::cout << "");
		std::cout << "Payroll: " << ePtr->earnings() * 4 + bonus << "\n\n";

		delete ePtr;
		ePtr = NULL;
	}

	for (int i = 0; i < employeePtrs.size(); ++i)
	{
		employeePtrs.at(i) = nullptr;
	}

	return 0;
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
