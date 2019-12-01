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

int main()
{
	// Registers
	int accumulator = 0;
	int instructionRegister = 0;
	int instructionCounter = 0;
	int operationCode = 0;
	int operand;
	// Memory
	int memory[MEMORY_SIZE] = { 0 };



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
		<< "*** Please enter your program one instruction ***"
		<< "*** (or data word) at a time. I will type the ***"
		<< "*** location number and a question mark (?).  ***"
		<< "*** You then type the word for that location. ***"
		<< "*** Type the sentinel -99999 to stop entering ***"
		<< "*** your program. ***";
}

void dump(int accumulator,
	int instructionRegister,
	int instructionCounter,
	int operationCode,
	int operand,
	int memory[])
{
	int firstColumnWidth = std::string("instructionRegister  ").size();
	int secondColumnWidth = std::string("+0000").size();
	std::cout << "REGISTERS"
		<< std::setw(firstColumnWidth)
		<< "accumulator"
		<< std::setw(secondColumnWidth)
		<< std::showpos
		<< std::setfill('0') << std::internal << accumulator << "\n"
		<< std::setw(firstColumnWidth)
		<< "instructionCounter"
		<< std::setw(secondColumnWidth)
		<< instructionCounter << "\n";
}
