#pragma once
#include <vector>
#include "Card.h"
#include "DeckOfCards.h"

class PokerHand
{
public:
	explicit PokerHand(int nCards = 5); // five-card poker hand
	bool contains_a_pair(void) const;
	bool contains_two_pairs(void) const;
	bool contains_n_of_a_kind(const int n) const;
	bool contains_a_flush(void) const;
	bool contains_a_straight(void) const;
	void print(void) const;
	int getPairNumbers(void) const;

private:
	std::vector< std::vector<Card>> handCards; // cards with the same face be in the same inner vector.
	DeckOfCards deck;
	int nPairs;
};

