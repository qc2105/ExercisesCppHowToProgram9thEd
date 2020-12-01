#include "PokerHand.h"
#include <iostream>
#include <string>
#include <algorithm>

PokerHand::PokerHand(std::vector<Card>& cardVec)
	:nPairs(0),
	size(cardVec.size())
{
	setCards(cardVec);
}

PokerHand::PokerHand(size_t _size)
	:nPairs(0),
	size(_size),
	maxFace(0),
	minFace(0)
{

}

bool PokerHand::contains_a_pair(size_t *faceOfTheNs, std::vector<Card> *kickers) const
{
	if (faceOfTheNs && kickers && nPairs > 0)
	{
		for (size_t i = 0; i < handCards.size(); i++)
		{
			if (handCards.at(i).size() >= 2)
			{
				*faceOfTheNs = handCards.at(i).at(0).getFace();
			}
			else if (handCards.at(i).size() == 1)
			{
				kickers->push_back(handCards.at(i).at(0));
			}
		}

		//sort kickers
		std::sort(kickers->rbegin(), kickers->rend(), cardCompare);

		return true;
	}
	else 
	{
		return nPairs > 0 ? true : false;
	}

	return false;
}

bool PokerHand::contains_two_pairs(size_t *biggerPairFace, size_t *smallerPairFace, std::vector<Card> *kickers) const
{
	if (biggerPairFace && smallerPairFace && kickers && nPairs >= 2)
	{
		*biggerPairFace = 0;
		*smallerPairFace = 0;
		for (size_t i = 0; i < handCards.size(); i++)
		{
			if (handCards.at(i).size() >= 2)
			{
				if (*biggerPairFace < handCards.at(i).at(0).getFace())
				{
					*biggerPairFace = handCards.at(i).at(0).getFace();
				}
				if (*smallerPairFace > handCards.at(i).at(0).getFace())
				{
					*smallerPairFace = handCards.at(i).at(0).getFace();
				}
			}
			else if (1 == handCards.at(i).size())
			{
				kickers->push_back(handCards.at(i).at(0));
			}
		}

		return true;
	}
	else
	{
		return nPairs >= 2 ? true : false;
	}
	return false;
}

bool PokerHand::contains_n_of_a_kind(const int n, size_t *faceOfTheNs) const
{
	for (size_t i = 0; i < handCards.size(); i++)
	{
		if (handCards.at(i).size() >= n)
		{
			if (faceOfTheNs)
			{
				*faceOfTheNs = handCards.at(i).at(0).getFace();
			}
			return true;
		}
	}
	return false;
}

bool PokerHand::contains_a_flush(void) const
{
	size_t suit = 0;

	// We get the first suit value
	for (size_t i = 0; i < handCards.size(); i++)
	{
		if (handCards.at(i).size() > 0) // there are cards with face i in the inner vec
		{
			suit = handCards.at(i).at(0).getSuit();
			break;
		}
	}

	// If there's a value that is different from the suit we got ealier, return false
	for (size_t i = 0; i < handCards.size(); i++)
	{
		for (size_t j = 0; j < handCards.at(i).size(); j++)
		{
			if (handCards.at(i).at(j).getSuit() != suit)
			{
				return false;
			}
		}
	}

	return true;
}

bool PokerHand::contains_a_straight(void) const
{
	if (0 == nPairs && 4 == (getMaxFace() - getMinFace()))
	{
		return true;
	}

	return false;
}

void PokerHand::print(void) const
{
	std::cout << "Rank: " << handRankToString(getRank()) << std::endl;
	for (size_t i = 0; i < handCards.size(); i++)
	{
		for (size_t j = 0; j < handCards.at(i).size(); j++)
		{
			std::cout << handCards.at(i).at(j).toString() << " ";
		}
		if (handCards.at(i).size() > 0)
		{
			std::cout << std::endl;
		}
	}
}

int PokerHand::getPairNumbers(void) const
{
	return nPairs;
}

size_t PokerHand::getSize(void) const
{
	return size;
}

size_t PokerHand::getMaxFace(void) const
{
	return maxFace;
}

void PokerHand::setMinMaxFace(void)
{
	std::vector<Card> cards;
	for (size_t i = 0; i < handCards.size(); i++)
	{
		for (size_t j = 0; j < handCards.at(i).size(); j++)
		{
			cards.push_back(handCards.at(i).at(j));
		}
	}

	size_t maxFace = cards.at(0).getFace();
	size_t minFace = cards.at(0).getFace();
	for (size_t i = 0; i < cards.size(); i++)
	{
		if (minFace > cards.at(i).getFace())
		{
			minFace = cards.at(i).getFace();
		}
		if (maxFace < cards.at(i).getFace())
		{
			maxFace = cards.at(i).getFace();
		}
	}

	this->minFace = minFace;
	this->maxFace = maxFace;
}

size_t PokerHand::getMinFace(void) const
{
	return minFace;
}

void PokerHand::setRank(void)
{
	if (contains_a_flush() && contains_a_straight() && getMaxFace() == 12)
	{
		rank = HandRank::RoyalFlush;
	}
	else if (contains_a_flush() && contains_a_straight())
	{
		rank = HandRank::StraightFlush;
	}
	else if (contains_n_of_a_kind(4))
	{
		rank = HandRank::FourSameFaceCards;
	}
	else if (contains_n_of_a_kind(3) && contains_two_pairs())
	{
		rank = HandRank::FullHouse;
	}
	else if (contains_a_flush())
	{
		rank = HandRank::Flush;
	}
	else if (contains_a_straight())
	{
		rank = HandRank::Straight;
	}
	else if (contains_n_of_a_kind(3))
	{
		rank = HandRank::ThreeSameFaceCards;
	}
	else if (contains_two_pairs())
	{
		rank = HandRank::TwoPairs;
	}
	else if (contains_a_pair())
	{
		rank = HandRank::OnePair;
	}
	else
	{
		rank = HandRank::HighCard;
	}
}

HandRank PokerHand::getRank(void) const
{
	return rank;
}

bool PokerHand::operator==(const PokerHand & b) const
{
	std::vector<Card> thisCards;
	std::vector<Card> bCards;

	getCards(thisCards);
	b.getCards(bCards);

	return thisCards == bCards;
}

bool PokerHand::operator<(const PokerHand & b) const
{
	if (this->rank < b.rank)
	{
		return true;
	}
	else if (this->rank == b.rank) // Reference: http://www.mypokerbasics.com/winning-poker-hand/77/
	{
		std::vector<Card> thisCardVec, bCardVec;

		size_t thisPairFace, bPairFace;
		std::vector<Card> thisKickers, bKickers;

		size_t thisBiggerPairFace, bBiggerPairFace;
		size_t thisSmallerPairFace, bSmallerPairFace;
		std::vector<Card> thisKicker, bKicker;

		size_t thisThreeFace, bThreeFace;
		size_t thisFourFace, bFourFace;
		switch (rank)
		{
		case HandRank::HighCard:
			this->getCards(thisCardVec);
			b.getCards(bCardVec);
			return thisCardVec < bCardVec;
			break;
		case HandRank::OnePair:
			this->contains_a_pair(&thisPairFace, &thisKickers);
			b.contains_a_pair(&bPairFace, &bKickers);
			if (thisPairFace < bPairFace)
			{
				return true;
			}
			else if (thisPairFace == bPairFace)
			{
				return thisKickers < bKickers;
			}
			return false;
			break;
		case HandRank::TwoPairs:
			this->contains_two_pairs(&thisBiggerPairFace, &thisSmallerPairFace, &thisKicker);
			b.contains_two_pairs(&bBiggerPairFace, &bSmallerPairFace, &bKicker);
			if (thisBiggerPairFace < bBiggerPairFace)
			{
				return true;
			}
			else if (thisBiggerPairFace > bBiggerPairFace)
			{
				return false;
			}
			else if (thisSmallerPairFace < bSmallerPairFace)
			{
				return true;
			}
			else if (thisSmallerPairFace > bSmallerPairFace)
			{
				return false;
			}
			else
			{
				return thisKicker < bKicker;
			}
			return false;
			break;
		case HandRank::ThreeSameFaceCards:
			this->contains_n_of_a_kind(3, &thisThreeFace);
			b.contains_n_of_a_kind(3, &bThreeFace);
			return thisThreeFace < bThreeFace;
			break;
		case HandRank::Straight:
			return this->getMaxFace() < b.getMaxFace();
			break;
		case HandRank::Flush:
			this->getCards(thisCardVec);
			b.getCards(bCardVec);
			return thisCardVec < bCardVec;
			break;
		case HandRank::FullHouse:
			this->contains_n_of_a_kind(3, &thisThreeFace);
			b.contains_n_of_a_kind(3, &bThreeFace);
			return thisThreeFace < bThreeFace;
			break;
		case HandRank::FourSameFaceCards:
			this->contains_n_of_a_kind(4, &thisFourFace);
			b.contains_n_of_a_kind(4, &bFourFace);
			return thisFourFace < bFourFace;
			break;
		case HandRank::StraightFlush:
			return this->getMaxFace() < b.getMaxFace();
			break;
		case HandRank::RoyalFlush:
			return false; // they are equal
			break;
		default:
			break;
		}
	}
	return false;
}

bool PokerHand::operator>(const PokerHand & b) const
{
	if (*this < b || *this == b)
	{
		return false;
	}

	return true;
}

void PokerHand::getCards(std::vector<Card>& cardVec) const
{
	for (size_t i = 0; i < handCards.size(); i++)
	{
		for (size_t j = 0; j < handCards.at(i).size(); j++)
		{
			cardVec.push_back(handCards.at(i).at(j));
		}
	}

	std::sort(cardVec.rbegin(), cardVec.rend(), cardCompare);
}

void PokerHand::setCards(std::vector<Card>& cardVec)
{
	handCards.clear();

	for (size_t i = 0; i < Card::faceStrings.size(); i++)
	{
		std::vector<Card> sameFaceCardVec;
		handCards.push_back(sameFaceCardVec);
	}
		
	for (size_t i = 0; i < cardVec.size(); i++)
	{
		handCards.at(cardVec.at(i).getFace()).push_back(cardVec.at(i));
	}

	for (size_t i = 0; i < handCards.size(); i++)
	{
		if (handCards.at(i).size() >= 2)
		{
			nPairs++;
		}
	}

	setMinMaxFace();
	setRank();
}

const std::string handRankToString(const HandRank rank)
{
	switch (rank)
	{
	case HandRank::HighCard:
		return std::string("HighCard");
		break;
	case HandRank::OnePair:
		return std::string("OnePair");
		break;
	case HandRank::TwoPairs:
		return std::string("TwoPairs");
		break;
	case HandRank::ThreeSameFaceCards:
		return std::string("ThreeSameFaceCards");
		break;
	case HandRank::Straight:
		return std::string("Straight");
		break;
	case HandRank::Flush:
		return std::string("Flush");
		break;
	case HandRank::FullHouse:
		return std::string("FullHouse");
		break;
	case HandRank::FourSameFaceCards:
		return std::string("FourSameFaceCards");
		break;
	case HandRank::StraightFlush:
		return std::string("StraightFlush");
		break;
	case HandRank::RoyalFlush:
		return std::string("RoyalFlush");
		break;
	default:
		break;
	}

	return std::string("Unkown rank");
}
