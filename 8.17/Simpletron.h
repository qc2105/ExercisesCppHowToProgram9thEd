#pragma once

#include <iostream>
#include <fstream>
#include <array>
#include <iomanip>
#include <string>

class Simpletron
{
public:
	Simpletron();
	~Simpletron();

	void dump();

	void welcome();

	void displayCounter(std::string str, int counter);
	void displayRegister(std::string str, int Register);
	void displayMemory(int memory[], int size);

	int execute();

	int loadSource(const char* pszSourcePath);

private:
	// Registers
	int accumulator;
	int instructionRegister;
	int instructionCounter;
	int operationCode;
	int operand;
	
	// Memory
	static const int MEMORY_SIZE = 100;
	int memory[MEMORY_SIZE];
	int inputWorld;
	int inputInteger;

	int appSize;
	bool halted;

	// Instruction Operators
	enum OperationCode
	{
		READ = 10, WRITE = 11,
		LOAD = 20, STORE = 21,
		ADD = 30, SUBTRACT = 31, DIVIDE = 32, MULTIPLY = 33, MODULUS = 34, POWER = 35,
		BRANCH = 40, BRANCHNEG = 41, BRANCHZERO = 42, HALT = 43,
		NEWLINE = 50
	};
};

