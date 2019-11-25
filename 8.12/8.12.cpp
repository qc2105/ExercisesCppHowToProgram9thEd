// 8.12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Requirement Analysis
// 1. char positionLine[76]; all elements initialized as blanks
// 2. Function moveTortoise
// 3. Function moveHare
// 4. int tortoisePosition; int harePosition;
// 5. int i = rand() % 10 + 1;
// 6. const char * const banner = "BANG !!!!!\nAND THEY'RE OFF !!!!!\n";
// 7. while (true) { showPosition(); hasTortoiseArrived(); hasHareArrived(); displayWinMesssage();? break;?}

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>
#include <Windows.h>

void moveTortoise(const int i, int *currentTortoisePosition, char * const positionLine);
void moveHare(const int i, int *currentHarePosition, char * const positionLine);
void showPositon(const int currentTortoisePosition, const int currentHarePosition, char * const positionLine);
bool hasTortoiseArrived(const int currentTortoisePosition);
bool hasHareArrived(const int currentHarePosition);
void displayWinMessage(const int currentTortoisePosition, const int currentHarePosition);

int main()
{
	char positionLine[77];
	memset(positionLine, ' ', sizeof(positionLine));
	int tortoisePosition = 1;
	int harePosition = 1;
	srand(static_cast<unsigned int>(time(0)));
	const char * const banner = "BANG !!!!!\nAND THEY'RE OFF !!!!!\n";

	std::cout << banner;
	while (true)
	{
		showPositon(tortoisePosition, harePosition, positionLine);
		int i = rand() % 10 + 1;
		moveHare(i, &harePosition, positionLine);
		moveTortoise(i, &tortoisePosition, positionLine);
		if (hasHareArrived(harePosition) || hasTortoiseArrived(tortoisePosition))
		{
			displayWinMessage(tortoisePosition, harePosition);
			break;
		}
		Sleep(250);
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

void moveTortoise(const int i, int * currentTortoisePosition, char * const positionLine)
{
	positionLine[*currentTortoisePosition] = ' ';
	// fast plod
	if (1 <= i and i <= 5)
	{
		*currentTortoisePosition += 3;
	}
	// slip
	else if (6 <= i and i <= 7)
	{
		if (*currentTortoisePosition - 6 <= 1)
		{
			*currentTortoisePosition = 1;
		}
		else 
		{
			*currentTortoisePosition -= 6;
		}
	}
	// slow plod
	else if (8 <= i and i <= 10)
	{
		*currentTortoisePosition += 1;
	}

	positionLine[*currentTortoisePosition] = 'T';
}

void moveHare(const int i, int * currentHarePosition, char * const positionLine)
{
	assert(1 <= i && i <= 10);
	positionLine[*currentHarePosition] = ' ';
	switch (i)
	{
	case 1:
	case 2:
		//sleep, no move at all
		break;
	case 3:
	case 4:
		// big hop
		*currentHarePosition += 9;
		break;
	case 5:
		// big sleep
		if (*currentHarePosition - 12 <= 1)
		{
			*currentHarePosition = 1;
		}
		else
		{
			*currentHarePosition -= 12;
		}
		break;
	case 6:
	case 7:
	case 8:
		// small hop
		*currentHarePosition += 1;
		break;
	case 9:
	case 10:
		// small slip
		if (*currentHarePosition - 2 <= 1)
		{
			*currentHarePosition = 1;
		}
		else
		{
			*currentHarePosition -= 2;
		}
		break;
	default:
		break;
	}

	positionLine[*currentHarePosition] = 'H';
}

void showPositon(const int currentTortoisePosition, const int currentHarePosition, char *const positionLine)
{
	if (currentHarePosition == currentTortoisePosition)
	{
		char *chPtr = positionLine + currentHarePosition;
		char oldTail = chPtr[7];
		strncpy_s(chPtr, sizeof("OUCH!!!"), "OUCH!!!", sizeof("OUCH!!!"));
		chPtr[7] = oldTail; // replace null terminal char with ' ';

		for (int i = 0; i < 77; i++)
		{
			std::cout << positionLine[i];
		}
		std::cout << std::endl;

		memset(chPtr, ' ', sizeof("OUCH!!!"));
	}
	else
	{
		for (int i = 0; i < 77; i++)
		{
			std::cout << positionLine[i];
		}
		std::cout << std::endl;
	}
}

bool hasTortoiseArrived(const int currentTortoisePosition)
{
	if (currentTortoisePosition >= 70)
	{
		return true;
	}

	return false;
}

bool hasHareArrived(const int currentHarePosition)
{
	if (currentHarePosition >= 70)
	{
		return true;
	}

	return false;
}

void displayWinMessage(const int currentTortoisePosition, const int currentHarePosition)
{
	if (currentHarePosition == currentTortoisePosition && currentHarePosition >= 70)
	{
		std::cout << "It's a tie\n";
	}
	else if (currentHarePosition > currentTortoisePosition && currentHarePosition >= 70)
	{
		std::cout << "Hare wins\n";
	}
	else if (currentTortoisePosition > currentHarePosition && currentTortoisePosition >= 70)
	{
		std::cout << "TORTOISE WINS!!! YAY!!!\n";
	}
}

