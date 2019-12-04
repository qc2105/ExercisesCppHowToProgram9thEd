// 8.16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <array>
#include <iomanip>
#include <string>

const int MEMORY_SIZE = 1000;

enum OperationCode
{
	READ = 10, WRITE = 11,
	LOAD = 20, STORE = 21,
	ADD = 30, SUBTRACT = 31, DIVIDE = 32, MULTIPLY = 33,
	BRANCH = 40, BRANCHNEG = 41, BRANCHZERO = 42, HALT = 43
};

void dump(
	int accumulator,
	int instructionRegister,
	int instructionCounter,
	int operationCode,
	int operand,
	int memory[]
	);

void welcome();

void displayCounter(std::string str, int counter);
void displayRegister(std::string str, int Register);
void displayMemory(int memory[], int size);

int main()
{
	// Registers
	int accumulator = 0;
	int instructionRegister = 0;
	int instructionCounter = 0;
	int operationCode = 0;
	int operand = 0;
	// Memory
	int memory[MEMORY_SIZE] = { 0 };
	int inputWorld = 0;
	int inputInteger = 0;

	int appSize = 0;
	bool halted = false;

	welcome();

	std::cout << std::endl;

	for (int instructionCounter = 0; instructionCounter < MEMORY_SIZE; instructionCounter++)
	{
		std::cout << std::setw(std::string("00").size()) << std::setfill('0') << instructionCounter << ' ' << "? ";
		while (true)
		{
			std::cin >> inputWorld;
			if (-99999 == inputWorld)
			{
				break;
			}
			if (-9999 <= inputWorld && inputWorld <= +9999)
			{
				break;
			}
			else
			{
				std::cout << "Invalid input.\n";
				std::cout << "Valid range: [-9999, +9999]\n";
				std::cout << "Please input again:\n";
			}
		}

		if (inputWorld == -99999)
		{
			std::cout << "*** Program loading completed ***\n";
			break;
		}
		else
		{
			memory[instructionCounter] = inputWorld;
			appSize++;
		}
	}

	std::cout << "*** Program execution begins  ***\n";

	for (int instructionCounter = 0; instructionCounter < MEMORY_SIZE && halted == false; instructionCounter++)
	{
		instructionRegister = memory[instructionCounter];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;
		switch (operationCode)
		{
		case READ:
			std::cout << "*** Please input an integer: ***\n";
			while (true)
			{
				std::cin >> inputInteger;
				if (-9999 <= inputInteger && inputInteger <= +9999)
				{
					break;
				}
				else
				{
					std::cout << "Invalid input.\n";
					std::cout << "Valid range: [-9999, +9999]\n";
					std::cout << "Please input again:\n";
				}
			}
			if (operand >= appSize || operand < 0)
			{
				std::cout << "*** Fatal: invalid memory location ***\n";
				std::cout << "*** Simpletron execution abnormally terminated ***\n";
				exit(-1);
			}
			memory[operand] = inputInteger;
			break;
		case WRITE:
			if (operand >= appSize || operand < 0)
			{
				std::cout << "*** Fatal: invalid memory location ***\n";
				std::cout << "*** Simpletron execution abnormally terminated ***\n";
				exit(-1);
			}
			std::cout << "\n*** Write out memory[" << operand << "]: " << memory[operand] << " ***\n" << std::endl;
			break;
		case LOAD:
			accumulator = memory[operand];
			break;
		case STORE:
			memory[operand] = accumulator;
			break;
		case ADD:
			accumulator += memory[operand];

			if (accumulator > +9999 || accumulator < -9999)
			{
				std::cout << "*** Fatal: overflow ***\n";
				std::cout << "*** Simpletron execution abnormally terminated ***\n";
				exit(-1);
			}
			break;
		case SUBTRACT:
			accumulator -= memory[operand];

			if (accumulator > +9999 || accumulator < -9999)
			{
				std::cout << "*** Fatal: overflow ***\n";
				std::cout << "*** Simpletron execution abnormally terminated ***\n";
				exit(-1);
			}
			break;
		case DIVIDE:
			if (0 == memory[operand])
			{
				std::cout << "*** Fatal: divide by zero ***\n";
				std::cout << "*** Simpletron execution abnormally terminated ***\n";
				exit(-1);
			}

			accumulator /= memory[operand];

			if (accumulator > +9999 || accumulator < -9999)
			{
				std::cout << "*** Fatal: overflow ***\n";
				std::cout << "*** Simpletron execution abnormally terminated ***\n";
				exit(-1);
			}
			break;
		case MULTIPLY:
			accumulator *= memory[operand];

			if (accumulator > +9999 || accumulator < -9999)
			{
				std::cout << "*** Fatal: overflow ***\n";
				std::cout << "*** Simpletron execution abnormally terminated ***\n";
				exit(-1);
			}
			break;
		case BRANCH:
			if (operand >= appSize || operand < 0)
			{
				std::cout << "*** Fatal: invalid memory location ***\n";
				std::cout << "*** Simpletron execution abnormally terminated ***\n";
				exit(-1);
			}

			instructionCounter = operand;
			instructionCounter--; // To mitigate ++ in the for loop
			break;
		case BRANCHNEG:
			if (operand >= appSize || operand < 0)
			{
				std::cout << "*** Fatal: invalid memory location ***\n";
				std::cout << "*** Simpletron execution abnormally terminated ***\n";
				exit(-1);
			}

			if (0 > accumulator)
			{
				instructionCounter = operand;
				instructionCounter--; // To mitigate ++ in the for loop
			}
			break;
		case BRANCHZERO:
			if (operand >= appSize || operand < 0)
			{
				std::cout << "*** Fatal: invalid memory location ***\n";
				std::cout << "*** Simpletron execution abnormally terminated ***\n";
				exit(-1);
			}

			if (0 == accumulator)
			{
				instructionCounter = operand;
				instructionCounter--; // To mitigate ++ in the for loop
			}
			break;
		case HALT:
			dump(accumulator,
				instructionRegister,
				instructionCounter,
				operationCode,
				operand, memory);
			halted = true;
			break;
		default:
			std::cout << "*** Fatal: unknown instruction! ***" << std::endl;
			std::cout << "*** Simpletron execution abnormally terminated ***\n";
			exit(-1);
			break;
		}
	}
   
	return 0;
}

void welcome()
{
	std::cout << "*** Welcome to Simpletron! ***\n\n"
		<< "*** Please enter your program one instruction ***" << std::endl
		<< "*** (or data word) at a time. I will type the ***" << std::endl
		<< "*** location number and a question mark (?).  ***" << std::endl
		<< "*** You then type the word for that location. ***" << std::endl
		<< "*** Type the sentinel -99999 to stop entering ***" << std::endl
		<< "*** your program. ***" << std::endl << std::endl;
}

void displayCounter(std::string str, int counter)
{
	size_t firstColumnWidth = std::string("instructionRegister  ").size();
	int counterWidth = 2;
	std::cout << std::setfill(' ') << std::internal
		<< std::setw(firstColumnWidth)
		<< std::left
		<< str
		<< "   "
		<< std::setw(counterWidth)
		<< std::setfill('0') << std::internal
		<< std::noshowpos
		<< counter << std::endl;
}

void displayRegister(std::string str, int Register)
{
	size_t firstColumnWidth = std::string("instructionRegister  ").size();
	size_t wordWidth = std::string("+0000").size();
	size_t counterWidth = std::string("00").size();

	std::cout << std::setfill(' ') << std::internal;
	std::cout << std::setw(firstColumnWidth) << std::left
		<< str
		<< std::setw(wordWidth)
		<< std::showpos
		<< std::setfill('0') << std::internal << Register << "\n";
}

void displayMemory(int memory[], int size)
{
	std::cout << "  ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::setw(std::string(" +0000").size()) << std::setfill(' ') << i;
	}
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0)
		{
			std::cout << std::setw(std::string("00").size()) << std::setfill(' ') << std::noshowpos << i << ' ';
		}
		std::cout << std::setw(std::string("+0000").size()) << std::setfill('0') << std::internal << std::showpos << memory[i] << ' ';
		if ((i - 9) % 10 == 0)
		{
			std::cout << std::endl;
		}
	}
}

void dump(int accumulator,
	int instructionRegister,
	int instructionCounter,
	int operationCode,
	int operand,
	int memory[])
{
	std::cout << "REGISTERS:\n";
	displayRegister("Accumulator", 0);
	displayCounter("instructionCounter", instructionCounter);
	displayRegister("instructionRegister", instructionRegister);
	displayCounter("operationCode", operationCode);
	displayCounter("operand", operand);

	std::cout << std::endl;
	std::cout << "MEMORY:\n";
	displayMemory(memory, MEMORY_SIZE);
}
