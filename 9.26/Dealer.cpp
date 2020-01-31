#include "Dealer.h"
#include "utils.h"
#include <iostream>

Dealer::Dealer(DeckOfCards & _deck, size_t _level)
	:deck(_deck),
	level(_level)
{
	deck.shuffle();
	std::vector<Card> initialCards;
	draw(currentHand.getSize(), &initialCards);
	currentHand.setCards(initialCards);
	getCombinations(currentHand.getSize() + level, currentHand.getSize(), combinationIndices);
}

PokerHand Dealer::getCurrentHand(void) const
{
	return currentHand;
}

void Dealer::draw(size_t numberOfCardsToDraw, std::vector<Card>* cards)
{
	if (!cards)
	{
		throw ("The pointer to cards ia null\n");
	}
	for (size_t i = 0; i < numberOfCardsToDraw; i++)
	{
		try
		{
			cards->push_back(deck.dealCard());
		}
		catch (const char *e)
		{
			std::cout << e << std::endl;
		}
	}
}

void Dealer::replace(std::vector<Card>* cards)
{
	if (!cards)
	{
		throw ("The pointer to cards is null.\n");
	}
	
	// collect all the eight cards
	std::vector<Card> eightCardsPool;
	currentHand.getCards(eightCardsPool);
	while (cards->size() > 0)
	{
		Card tempCard = cards->back();
		cards->pop_back();
		eightCardsPool.push_back(tempCard);
	}
	// find all those combinations put them into std::vector<std::vector<Card>>
	std::vector<std::vector<Card>> handsPool;
	for (size_t i = 0; i < combinationIndices.size(); i++)
	{
		std::vector<Card> tempHand;
		for (size_t j = 0; j < combinationIndices.at(i).size(); j++)
		{
			tempHand.push_back(eightCardsPool.at(combinationIndices.at(i).at(j)));
		}
		handsPool.push_back(tempHand);
	}

	// make the hand with the highest value the currentHand
	for (size_t i = 0; i < handsPool.size(); i++) // should be 56 loops
	{
		PokerHand tempPokerHand;
		tempPokerHand.setCards(handsPool.at(i));
		if (currentHand < tempPokerHand)
		{
			currentHand = tempPokerHand;
		}
	}

	// find the left cards, return them back to the deck
	std::vector<Card> cardsHold, cardsLeft;
	currentHand.getCards(cardsHold);
	std::sort(eightCardsPool.rbegin(), eightCardsPool.rend(), cardCompare);

	for (size_t i = 0; i < eightCardsPool.size() && cardsLeft.size() < level; i++)
	{
		if (!std::binary_search(cardsHold.rbegin(), cardsHold.rend(), eightCardsPool.at(i), cardCompare))
		{
			cardsLeft.push_back(eightCardsPool.at(i));
		}
	}

	deck.receiveCards(cardsLeft);
}

void Dealer::upgradeCurrentHand(void)
{
	std::vector<Card> cards;
	draw(level, &cards);
	replace(&cards);
}
