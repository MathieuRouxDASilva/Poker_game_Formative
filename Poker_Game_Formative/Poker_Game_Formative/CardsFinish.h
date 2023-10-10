#pragma once
#include <vector>
#include <map>
#include "Deck.h"

//enum with all the possible results
enum CardsCombo
{
	HightCard,
	Pair,
	TwoPairs,
	ThreeOfAKind,
	Straight,
	Flush,
	Full,
	FourOfAKind,
	StraightFlush,
};

//to string result
std::string ToString(CardsCombo _value);

//function to evaluate the result
CardsCombo Evaluate(const std::vector<Card>& _Hand);

//map for it
std::map<Rank, int> RankOccurences(const std::vector<Card>& compoundHand);
std::map<Suit, int> SuitOccurences(const std::vector<Card>& compoundHand);

//all the bool for the result
bool HasPair(const std::vector<Card>& _compoundHand);
bool HasTwoPairs(const std::vector<Card>& _compoundHand);
bool HasThreeOfAKind(const std::vector<Card>& _compoundHand);
bool HasFourOfAKind(const std::vector<Card>& _compoundHand);
bool HasFull(const std::vector<Card>& _compoundHand);
bool HasStraight(const std::vector<Card>& _compoundHand);
bool HasStraightFlush(const std::vector<Card>& _compoundHand);
bool HasFlush(const std::vector<Card>& _compoundHand);