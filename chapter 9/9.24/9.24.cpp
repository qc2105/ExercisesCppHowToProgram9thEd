// 9.24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "DeckOfCards.h"
#include "Card.h"
#include "PokerHand.h"

int main()
{
    std::cout << "Hello World!\n";
	
	PokerHand hand;
	hand.print();

	hand.contains_a_pair() ? (std::cout << "The hand contains a pair.\n") : (std::cout << "The hand has no pair.\n");
	hand.contains_two_pairs() ? (std::cout << "The hand contains two pairs.\n") : (std::cout << "The hand doesn't contain two pairs.\n");
	hand.contains_n_of_a_kind(3) ? (std::cout << "The hand contains three of a kind.\n") : (std::cout << "The hand doesn't contain three of a kind.\n");
	hand.contains_n_of_a_kind(4) ? (std::cout << "The hand contains four of a kind.\n") : (std::cout << "The hand doesn't contain four of a kind.\n");
	hand.contains_a_flush() ? (std::cout << "The hand contains a flush.\n") : (std::cout << "The hand doesn't contain a flush.\n");
	hand.contains_a_straight() ? (std::cout << "The hand contains a straight.\n") : (std::cout << "The hand doesn't contain a straight.\n");
	
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
