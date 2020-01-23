#pragma once
#include "Card.h"
#include <vector>

class DeckOfCards
{
public:
	explicit DeckOfCards(void);
	void shuffle(void);
	Card dealCard(void);
	bool moreCards(void) const;

private:
	int currentCard;
	std::vector<Card> deck;
};

