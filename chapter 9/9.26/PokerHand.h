#pragma once
#include <vector>
#include "Card.h"
#include "DeckOfCards.h"
#include <string>

// Reference: https://www.cardplayer.com/rules-of-poker/hand-rankings
enum class HandRank
{
	HighCard = 0,
	OnePair,
	TwoPairs,
	ThreeSameFaceCards,
	Straight,
	Flush,
	FullHouse,
	FourSameFaceCards,
	StraightFlush,
	RoyalFlush
};

const std::string handRankToString(const HandRank rank);

class PokerHand
{
public:
	explicit PokerHand(std::vector<Card>& cardVec); // five-card poker hand
	PokerHand(size_t _size=5);

	bool contains_a_pair(size_t *faceOfTheNs = nullptr, std::vector<Card> *kickers = nullptr) const;
	bool contains_two_pairs(size_t *biggerPairFace = nullptr, size_t *smallerPairFace = nullptr, std::vector<Card> *kickers = nullptr) const;
	bool contains_n_of_a_kind(const int n, size_t *faceOfTheNs = nullptr) const;
	bool contains_a_flush(void) const;
	bool contains_a_straight(void) const;
	void print(void) const;
	int getPairNumbers(void) const;
	size_t getSize(void) const;

	size_t getMaxFace(void) const;
	void setMinMaxFace(void);
	size_t getMinFace(void) const;

	void setRank(void);
	HandRank getRank(void) const;

	bool operator ==(const PokerHand &b) const;
	bool operator <(const PokerHand & b) const;
	bool operator >(const PokerHand &b) const;

	void getCards(std::vector<Card> &cardVec) const; // ouput sorted cards, desc
	void setCards(std::vector<Card> &cardVec); // replace handCards with cards in cardVec

private:
	std::vector< std::vector<Card>> handCards; // cards with the same face be in the same inner vector.
	size_t maxFace;
	size_t minFace;
	HandRank rank;
	int nPairs;
	size_t size;
};

