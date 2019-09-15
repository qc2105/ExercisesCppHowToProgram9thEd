// Chapter5-exercises-5.21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	int paycode = 0;
   
	while (true)
	{
		std::cout << "Please input the paycode:";
		std::cin >> paycode;
		if (-1 == paycode)
			return 0;
		if (paycode >= 1 && paycode <= 4)
		{
		}
		else
		{
			std::cout << "Please input numbers: 1, 2, 3 or 4\n";
			continue;
		}

		switch (paycode)
		{
		case 1:
			std::cout << "Please input the fixed salary:";
			double fixed_salary;
			std::cin >> fixed_salary;
			std::cout << "The manager's weekly pay is: " << fixed_salary << std::endl;
			break;
		case 2:
			std::cout << "Please input the hourly wage:";
			double hourly_wage;
			std::cin >> hourly_wage;
			std::cout << "Please input the worker's weekly working hours:";
			double hours;
			std::cin >> hours;
			if (hours <= 40)
			{
				std::cout << "The hourly worker's weekly pay is: " << hourly_wage * hours << std::endl;
			}
			else
			{
				std::cout << "The hourly worker's weekyly pay is: " << hourly_wage * 40 + 1.5 * (hours - 40) * hourly_wage << std::endl;
			}
			break;
		case 3:
			std::cout << "Please input the commission worker's gross weekly sales:";
			double weekly_sales;
			std::cin >> weekly_sales;
			std::cout << "The commission worker's weekly pay is: " << 250 + 0.0057 * weekly_sales << std::endl;
			break;
		case 4:
			std::cout << "Please input the unit item price:";
			double price;
			std::cin >> price;
			std::cout << "Please input the number of items made:";
			double numbers;
			std::cin >> numbers;
			std::cout << "The pieceworker's weekly pay is: " << price * numbers << std::endl;
			break;
		default:
			std::cout << "Invalid paycode\n";
			break;
		}
	}
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
