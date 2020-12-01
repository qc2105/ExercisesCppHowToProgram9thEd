#pragma once
#include "PokerHand.h"
#include "DeckOfCards.h"

class Dealer
{
public:
	Dealer(DeckOfCards &deck, size_t level = 3);
	
	PokerHand getCurrentHand(void) const;
	void upgradeCurrentHand(void);

private:
	void draw(size_t numberOfCardsToDraw, std::vector<Card> *cards);
	void replace(std::vector<Card> *cards);
	bool isCardInVec(Card &card, std::vector<Card> &vec);

	DeckOfCards &deck;
	PokerHand currentHand;
	size_t level;

	std::vector<std::vector<size_t> > combinationIndices;
};

