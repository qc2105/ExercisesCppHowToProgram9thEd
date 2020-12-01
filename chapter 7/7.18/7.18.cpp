// Fig. 6.11: fig06_11.cpp
// Craps simulation.
#include "pch.h"
#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
#include <array>
#include <iomanip>

using namespace std;

bool game(int & nThRoll);

unsigned int rollDice(); // rolls dice, calculates and displays sum

int main()
{
	// randomize random number generator using current time
	srand(static_cast<unsigned int>(time(0)));

	std::array<int, 20> winsInRoll = { 0 };
	std::array<int, 20> lostInRoll = { 0 };
	int winsAfter20th = 0;
	int lostAfter20th = 0;
	for (int i = 0; i < 1000; i++)
	{
		int nThRoll = 0;
		bool isWin = game(nThRoll);
		if (isWin)
		{
			if (nThRoll > 20)
			{
				winsAfter20th++;
			}
			else if (nThRoll != 0)
			{
				winsInRoll[nThRoll - 1] += 1;
			}
		}
		else
		{
			if (nThRoll > 20)
			{
				lostAfter20th++;
			}
			else if (nThRoll != 0)
			{
				lostInRoll[nThRoll - 1] += 1;
			}
		}
	}
	
	for (int i = 1; i <= 20; i++)
	{
		std::cout << std::setw(4) << i;
	}
	std::cout << std::setw(4) << " >20";
	std::cout << '\n';
	int winSum = 0;
	for (auto v : winsInRoll)
	{
		std::cout << std::setw(4) << v;
		winSum += v;
	}
	std::cout << std::setw(4) << winsAfter20th;
	winSum += winsAfter20th;
	std::cout << '\n';

	std::cout << "---------------\n";

	for (int i = 1; i <= 20; i++)
	{
		std::cout << std::setw(4) << i;
	}
	std::cout << std::setw(4) << " >20";
	std::cout << '\n';
	int lostSum = 0;
	for (auto v : lostInRoll)
	{
		std::cout << std::setw(4) << v;
		lostSum += v;
	}
	std::cout << std::setw(4) << lostAfter20th;
	lostSum += lostAfter20th;
	std::cout << '\n';
	std::cout << "---------------\n";
	std::cout << std::setw(4) << "win" << " vs " << std::setw(4) << "lost" << '\n';
	std::cout << std::setw(4) << winSum << " vs " << std::setw(4) << lostSum << '\n';
	std::cout << "---------------\n";
	long totalSum = 0;
	for (int i = 1; i <= 20; i++)
	{
		totalSum += winsInRoll[i - 1] * i + lostInRoll[i - 1] * i;
	}
	std::cout << "Average length for game less than or equal 20 rolls: " 
		<< static_cast<double>(totalSum) / (1000 - winsAfter20th - lostAfter20th) << "\n";

	return 0;
} // end main

bool game(int & nThRoll)
{
	// enumeration with constants that represent the game status
	enum Status { CONTINUE, WON, LOST }; // all caps in constants

	unsigned int myPoint = 0; // point if no win or loss on first roll
	Status gameStatus = CONTINUE; // can contain CONTINUE, WON or LOST
	unsigned int sumOfDice = rollDice(); // first roll of the dice

	// determine game status and point (if needed) based on first roll
	switch (sumOfDice)
	{
	case 7: // win with 7 on first roll
	case 11: // win with 11 on first roll 
		nThRoll = 1;
		gameStatus = WON;
		break;
	case 2: // lose with 2 on first roll
	case 3: // lose with 3 on first roll
	case 12: // lose with 12 on first roll
		nThRoll = 1;
		gameStatus = LOST;
		break;
	default: // did not win or lose, so remember point
		gameStatus = CONTINUE; // game is not over
		nThRoll++;
		myPoint = sumOfDice; // remember the point
		cout << "Point is " << myPoint << endl;
		break; // optional at end of switch  
	} // end switch 

	// while game is not complete
	while (CONTINUE == gameStatus) // not WON or LOST
	{
		nThRoll++;
		sumOfDice = rollDice(); // roll dice again

		// determine game status
		if (sumOfDice == myPoint) // win by making point
			gameStatus = WON;
		else
			if (sumOfDice == 7) // lose by rolling 7 before point
				gameStatus = LOST;
	} // end while 

	// display won or lost message
	if (WON == gameStatus)
	{
		cout << "Player wins" << endl;
		return true;
	}
	else
	{
		cout << "Player loses" << endl;
		return false;
	}
}

// roll dice, calculate sum and display results
unsigned int rollDice()
{
	// pick random die values
	unsigned int die1 = 1 + rand() % 6; // first die roll
	unsigned int die2 = 1 + rand() % 6; // second die roll

	unsigned int sum = die1 + die2; // compute sum of die values

	// display results of this roll
	cout << "Player rolled " << die1 << " + " << die2
		<< " = " << sum << endl;
	return sum; // return sum of dice
} // end function rollDice


/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
