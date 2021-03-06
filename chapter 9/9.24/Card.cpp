#include "Card.h"

const std::array<std::string, 4> Card::suitStrings = {"Spades", "Hearts", "Diamonds", "Clubs"};
const std::array<std::string, 13> Card::faceStrings = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };

Card::Card(size_t _face, size_t _suit)
	:face(_face),
	suit(_suit)
{
}

std::string Card::toString(void) const
{
	return faceStrings.at(face) + " of " + suitStrings.at(suit) + ".";
}
