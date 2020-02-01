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

bool Card::operator<(const Card & b) const
{
	return this->getFace() < b.getFace();
}

bool Card::operator==(const Card & b) const
{
	return this->getFace() == b.getFace();
}

bool Card::is(const Card & b) const
{
	if (this->getFace() != b.getFace() || this->getSuit() != b.getSuit())
	{
		return false;
	}

	return true;
}

bool Card::operator>(const Card & b) const
{
	if (*this < b || *this == b)
	{
		return false;
	}
	return true;
}

bool cardCompare(const Card & a, const Card & b)
{
	return a < b;
}
