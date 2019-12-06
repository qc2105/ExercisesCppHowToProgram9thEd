#include "Simpletron.h"

Simpletron::Simpletron()
{
}

Simpletron::~Simpletron()
{
}

void Simpletron::welcome()
{
	std::cout << "*** Welcome to Simpletron! ***\n\n"
		<< "*** Please enter your program one instruction ***" << std::endl
		<< "*** (or data word) at a time. I will type the ***" << std::endl
		<< "*** location number and a question mark (?).  ***" << std::endl
		<< "*** You then type the word for that location. ***" << std::endl
		<< "*** Type the sentinel -99999 to stop entering ***" << std::endl
		<< "*** your program. ***" << std::endl << std::endl;
}

void Simpletron::displayCounter(std::string str, int counter)
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

void Simpletron::displayRegister(std::string str, int Register)
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

void Simpletron::displayMemory(int memory[], int size)
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

int Simpletron::execute()
{
	std::cout << "*** Program execution begins  ***\n";

	for (instructionCounter = 0; instructionCounter < MEMORY_SIZE && halted == false; instructionCounter++)
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
		case MODULUS:
			accumulator %= memory[operand];

			if (accumulator > +9999 || accumulator < -9999)
			{
				std::cout << "*** Fatal: overflow ***\n";
				std::cout << "*** Simpletron execution abnormally terminated ***\n";
				exit(-1);
			}
			break;
		case POWER:
			accumulator = pow(accumulator, memory[operand]);

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
		case NEWLINE:
			std::cout << "\n";
			break;
		case HALT:
			dump();
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

int Simpletron::loadSource(const char* pszSourcePath)
{
	std::string line;
	std::ifstream sourceFile(pszSourcePath);
	if (!sourceFile.is_open())
	{
		std::cout << "Open sml source file failed\n";
		return -1;
	}

	welcome();

	std::cout << std::endl;

	for (instructionCounter = 0; instructionCounter < MEMORY_SIZE; instructionCounter++)
	{
		std::cout << std::setw(std::string("00").size()) << std::setfill('0') << instructionCounter << ' ' << "? ";

		std::getline(sourceFile, line);
		inputWorld = std::stoi(line);
		std::cout << inputWorld << std::endl;
		if (inputWorld == -99999)
		{
			std::cout << "*** Program loading completed ***\n";
			break;
		}
		else if (-9999 <= inputWorld && inputWorld <= +9999)
		{
			memory[instructionCounter] = inputWorld;
			appSize++;
		}
		else
		{
			std::cout << "Invalid input in line: " << appSize << std::endl;
			std::cout << "Valid range: [-9999, +9999]\n";
			return -1;
		}
	}

	sourceFile.close();
	return 0;
}

void Simpletron::dump()
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