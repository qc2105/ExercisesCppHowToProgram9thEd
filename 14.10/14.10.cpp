// 14.10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Person.h"

int main()
{
    std::cout << "Hello World!\n";

	enum OP {INIT = '1', NEW = '2', UPDATE = '3', DEL = '4', PRINT = '5', QUIT = '6'};

	std::fstream ioPerson;

	while (true)
	{
		std::cout << "Please input your operation choice:\n"
			<< "1. Initialize the file with 100 zero records\n"
			<< "2. Add a new record\n"
			<< "3. Update a record\n"
			<< "4. Delete a record\n"
			<< "5. Print records\n"
			<< "6. Quit the app\n";

		char choice;
		std::cin >> choice;
		if (!::isdigit(choice))
		{
			continue;
		}

		if (choice == INIT)
		{
			ioPerson.open("nameage.dat", std::ios::out | std::ios::binary);
			if (!ioPerson)
			{
				std::cout << "Can't open file nameage.dat\n";
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			ioPerson.open("nameage.dat", std::ios::in | std::ios::out | std::ios::binary);
			if (!ioPerson)
			{
				std::cout << "Can't open file nameage.dat\n";
				exit(EXIT_FAILURE);
			}
		}

		switch (choice)
		{
		case INIT:
			name14_10::initialize(ioPerson);
			break;
		case NEW:
			name14_10::add(ioPerson);
			break;
		case UPDATE:
			name14_10::update(ioPerson);
			break;
		case DEL:
			name14_10::del(ioPerson);
			break;
		case PRINT:
			name14_10::print(ioPerson);
			break;
		case QUIT:
			ioPerson.close();
			return 0;
		default:
			break;
		}

		ioPerson.close();
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

