#pragma once

#include <iostream>
#include <fstream>
#include <array>
#include <iomanip>
#include <string>
#include <cmath>

class Simpletron
{
public:
	Simpletron();
	~Simpletron();

	void dump();

	void welcome();

	template <class T>
	void displayCounter(std::string str, T counter);
	template <class T>
	void displayRegister(std::string str, T Register);
	template <class T>
	void displayMemory(T memory[], int size);

	int execute();

	int loadSource(const char* pszSourcePath);

private:
	// Registers
	double accumulator;
	double instructionRegister;
	int instructionCounter;
	int operationCode;
	double operand;
	
	// Memory
	static const int MEMORY_SIZE = 100;
	double memory[MEMORY_SIZE];
	int inputWorld;
	int inputInteger;

	int appSize;
	bool halted;
	bool debugON;

	// Instruction Operators
	enum OperationCode
	{
		READ = 10, WRITE = 11,
		LOAD = 20, STORE = 21,
		ADD = 30, SUBTRACT = 31, DIVIDE = 32, MULTIPLY = 33, MODULUS = 34, POWER = 35,
		BRANCH = 40, BRANCHNEG = 41, BRANCHZERO = 42, HALT = 43, SML_DEBUG = 44,
		NEWLINE = 50
	};
};

