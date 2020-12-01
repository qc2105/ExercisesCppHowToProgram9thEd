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
	void receiveCards(const std::vector<Card> &cards);

private:
	int currentCard;
	std::vector<Card> deck;
};

