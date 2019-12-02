// 8.16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <array>
#include <iomanip>
#include <string>

const int MEMORY_SIZE = 100;

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
	int inputWord = 0;

	welcome();

	std::cout << std::endl;

	for (int instructionCounter = 0; instructionCounter < MEMORY_SIZE; instructionCounter++)
	{
		std::cout << std::setw(std::string("00").size()) << std::setfill('0') << i << ' ' << "? ";
		std::cin >> memory[instructionCounter];
	}
    
	dump(accumulator, 
		instructionRegister, 
		instructionCounter, 
		operationCode, 
		operand, memory);

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
	displayMemory(memory, 100);
}
