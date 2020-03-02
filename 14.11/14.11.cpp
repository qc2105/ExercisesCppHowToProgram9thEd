// 14.11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Hardware.h"

const std::string FILENAME = "hardware.dat";

int main()
{
	std::cout << "Hello World!\n";

	enum OP { INIT = '1', NEW = '2', UPDATE = '3', DEL = '4', PRINT = '5', QUIT = '6' };

	std::fstream ioHardware;

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
			ioHardware.open(FILENAME, std::ios::out | std::ios::binary);
			if (!ioHardware)
			{
				std::cout << "Can't open file " + FILENAME + "\n";
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			ioHardware.open(FILENAME, std::ios::in | std::ios::out | std::ios::binary);
			if (!ioHardware)
			{
				std::cout << "Can't open file " + FILENAME + "\n";
				exit(EXIT_FAILURE);
			}
		}

		switch (choice)
		{
		case INIT:
			initialize(ioHardware);
			break;
		case NEW:
			add(ioHardware);
			break;
		case UPDATE:
			update(ioHardware);
			break;
		case DEL:
			del(ioHardware);
			break;
		case PRINT:
			print(ioHardware);
			break;
		case QUIT:
			ioHardware.close();
			return 0;
		default:
			break;
		}

		ioHardware.close();
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
