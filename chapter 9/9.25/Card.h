#pragma once
#include <array>

class Card
{
public:
	explicit Card(size_t face, size_t suit);
	std::string toString(void) const;

	static const std::array<std::string, 4> suitStrings;
	static const std::array<std::string, 13> faceStrings;
	size_t getFace(void) const { return face; }
	size_t getSuit(void) const { return suit; }

	bool operator <(const Card &b) const;
	bool operator ==(const Card &b) const;
	bool operator >(const Card &b) const;

private:
	size_t face;
	size_t suit;
};

bool cardCompare(const Card &a, const Card &b);