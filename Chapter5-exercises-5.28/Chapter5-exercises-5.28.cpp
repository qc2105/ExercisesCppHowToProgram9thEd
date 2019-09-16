// Chapter5-exercises-5.28.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::cout << "The Twelve days of Christmas\n\n"; 
	std::vector<std::string> verses;
	for (int i = 1; i <= 12; i++)
	{
		std::cout << "On the ";
		switch (i)
		{
		case 1:
			std::cout << "first";
			break;
		case 2:
			std::cout << "second";
			break;
		case 3:
			std::cout << "third";
			break;
		case 4:
			std::cout << "fourth";
			break;
		case 5:
			std::cout << "fifth";
			break;
		case 6:
			std::cout << "sixth";
			break;
		case 7:
			std::cout << "seventh";
			break;
		case 8:
			std::cout << "eighth";
			break;
		case 9:
			std::cout << "ninth";
			break;
		case 10:
			std::cout << "tenth";
			break;
		case 11:
			std::cout << "eleventh";
			break;
		case 12:
			std::cout << "twelfth";
			break;
		default: // impossible case;
			break;
		}
		std::cout << " day of Christmas" << std::endl;
		std::cout << "my true love sent to me: " << std::endl;
		
		switch (i)
		{
		case 1:
			std::cout << "A Partridge in a Pear Tree" << std::endl;
			break;
		case 2:
			verses.push_back("and a Partridge in a Pear Tree");
			verses.push_back("Two Turtle Doves");
			break;
		case 3:
			verses.push_back("Three French Hens");
			break;
		case 4:
			verses.push_back("Four Calling Birds");
			break;
		case 5:
			verses.push_back("Five Golden Rings");
			break;
		case 6:
			verses.push_back("Six Geese a Laying");
			break;
		case 7:
			verses.push_back("Seven Swans a Swimming");
			break;
		case 8:
			verses.push_back("Eight Maids a Milking");
			break;
		case 9:
			verses.push_back("Nine Ladies Dancing");
			break;
		case 10:
			verses.push_back("Ten Lords a Leaping");
			break;
		case 11:
			verses.push_back("Eleven Pipers Piping");
			break;
		case 12:
			verses.push_back("12 Drummers Drumming");
			break;
		default: // impossible case;
			break;
		}
		if (1 != i)
		{
			std::reverse(verses.begin(), verses.end());
		}
		for (int k = 0; k < verses.size(); k++)
		{
			std::cout << verses[k] << std::endl;
		}
		std::reverse(verses.begin(), verses.end());
		std::cout << std::endl;
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
