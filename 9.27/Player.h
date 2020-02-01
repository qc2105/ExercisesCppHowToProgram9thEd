#pragma once
#include "PokerHand.h"
#include "DeckOfCards.h"

class Player
{
public:
	Player(DeckOfCards &deck, size_t level = 3);

	PokerHand getCurrentHand(void) const;
	void upgradeCurrentHand(void);

private:
	void draw(size_t numberOfCardsToDraw, std::vector<Card> *cards);
	void replace(std::vector<Card> *cards);
	bool swapCards(size_t iCurrentHand, size_t iDrawedCards, std::vector<Card> &currentCards, std::vector<Card> *drawedCards);

	DeckOfCards &deck;
	PokerHand currentHand;
	size_t level;
};

