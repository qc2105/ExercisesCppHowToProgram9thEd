// Fig. 6.11: fig06_11.cpp
// Craps simulation.
#include "pch.h"
#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
#include <random>

using namespace std;

unsigned int rollDice(); // rolls dice, calculates and displays sum
// randomize random number generator using current time
default_random_engine engine(static_cast<unsigned int>(time(0)));

int main()
{
	// enumeration with constants that represent the game status
	enum Status { CONTINUE, WON, LOST }; // all caps in constants

	double bankBalance = 1000;

	while (bankBalance > 0)
	{
		std::cout << "Please input a wager:\n";

		double wager;

		while (true)
		{
			std::cin >> wager;
			if (wager <= bankBalance)
			{
				break;
			}
			else
			{
				std::cout << "Please input a valid wager, which is less or equal than your bankBalance: " << bankBalance << "\n";
			}
		}

		unsigned int myPoint = 0; // point if no win or loss on first roll
		Status gameStatus = CONTINUE; // can contain CONTINUE, WON or LOST
		unsigned int sumOfDice = rollDice(); // first roll of the dice

		// determine game status and point (if needed) based on first roll
		switch (sumOfDice)
		{
		case 7: // win with 7 on first roll
		case 11: // win with 11 on first roll           
			gameStatus = WON;
			break;
		case 2: // lose with 2 on first roll
		case 3: // lose with 3 on first roll
		case 12: // lose with 12 on first roll             
			gameStatus = LOST;
			break;
		default: // did not win or lose, so remember point
			gameStatus = CONTINUE; // game is not over
			myPoint = sumOfDice; // remember the point
			cout << "Point is " << myPoint << endl;
			break; // optional at end of switch  
		} // end switch 

		// while game is not complete
		while (CONTINUE == gameStatus) // not WON or LOST
		{
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
			bankBalance += wager;
			if (bankBalance < 1100 && bankBalance > 1000)
			{
				std::cout << "You're up big. Now's the time to cash in your chips\n";
			}
		}
		else
		{
			cout << "Player loses" << endl;
			bankBalance -= wager;
			if (bankBalance < 100 && bankBalance > 0)
			{
				std::cout << "Oh, you're going for broke, huh?\n";
			}
			else if (bankBalance > 500)
			{
				std::cout << "Aw cmon, take a chance!\n";
			}
		}

		std::cout << "Your new bankBalance: " << bankBalance << std::endl;
	}

	std::cout << "Sorry. You busted!\n";

	return 0;
} // end main

// roll dice, calculate sum and display results
unsigned int rollDice()
{
	// pick random die values
	uniform_int_distribution<unsigned int> randomInt(1, 6);

	unsigned int die1 = randomInt(engine); // first die roll
	unsigned int die2 = randomInt(engine); // second die roll

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
