#include "Player.h"
#include <iostream>
#include <algorithm>
#include "InputProcessor.h"

Player::Player(DeckOfCards & _deck, size_t _level)
	:deck(_deck),
	level(_level)
{
	deck.shuffle();
	std::vector<Card> initialCards;
	draw(currentHand.getSize(), &initialCards);
	currentHand.setCards(initialCards);
}

PokerHand Player::getCurrentHand(void) const
{
	return currentHand;
}

void Player::upgradeCurrentHand(void)
{
	std::vector<Card> cards;
	draw(level, &cards);
	replace(&cards);
}

void Player::draw(size_t numberOfCardsToDraw, std::vector<Card>* cards)
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

void Player::replace(std::vector<Card>* cards)
{
	//display the current hand
	std::cout << "Current hand" << std::endl;
	currentHand.print();
	std::cout << "------------------------" << std::endl;

	//display drawed cards
	std::cout << "Cards drawed" << std::endl;
	if (!cards)
	{
		throw "A null pointer to cards in function replace";
	}
	std::sort(cards->rbegin(), cards->rend(), cardCompare);
	
	for (size_t i = 0; i < cards->size(); i++)
	{
		std::cout << cards->at(i).toString() << ' ';
	}
	std::cout << std::endl;
	std::cout << "------------------------" << std::endl;

	InputProcessor ip;

	std::vector<std::vector<size_t>> actions;
	ip.getInts(actions);

	std::vector<Card> currentCards;
	currentHand.getCards(currentCards);
	for (size_t i = 0; i < actions.size(); i++)
	{
		swapCards(actions.at(i).at(0), actions.at(i).at(1), currentCards, cards);
	}
	currentHand.setCards(currentCards);
	
	std::cout << "Replaced cards" << std::endl;
	currentHand.print();
	std::cout << "------------------------" << std::endl;
}

bool Player::swapCards(size_t iCurrentHand, size_t iDrawedCards, std::vector<Card> &currentCards, std::vector<Card> *drawedCards)
{
	size_t handPos = iCurrentHand - 1;
	size_t drawedPos = iDrawedCards - 1;

	if (!drawedCards)
	{
		throw "Null pointer in swapCards";
		return false;
	}
	if (handPos >= currentCards.size() || drawedPos >= drawedCards->size())
	{
		return false;
	}
	
	Card tempCard = currentCards.at(handPos);
	currentCards.at(handPos) = drawedCards->at(drawedPos);
	drawedCards->at(drawedPos) = tempCard;

	return true;
}
