#include "CardsFinish.h"
#include <map>
#include <set>

//function to write the result of the differents cards
std::string ToString(CardsCombo _value)
{
	switch (_value)
	{
	case HightCard: return "High Card";  break;
	case Pair: return "Pair"; break;
	case TwoPairs: return "Two Pairs"; break;
	case ThreeOfAKind: return "Three of a kind"; break;
	case FourOfAKind: return "For of a kind"; break;
	case Full: return "Full"; break;
	case Straight: return "Straight"; break;
	case Flush: return "Flush"; break;
	case StraightFlush: return "Straight flush"; break;

	default:
		return "_no_value_";
	}


}

//function to evaluate what is the otimal combo the player has
CardsCombo Evaluate(const std::vector<Card>& _hand)
{

	// Compose Player and table Hands ------------
	std::vector<Card> _compoundHand;

	for (auto c : _hand)
		_compoundHand.emplace_back(c);

	for (auto c : Table)
		_compoundHand.emplace_back(c);

	if (HasStraightFlush(_compoundHand))
	{
		return StraightFlush;
	}
	else if (HasFourOfAKind(_compoundHand))
	{
		return FourOfAKind;
	}
	else if (HasFull(_compoundHand))
	{
		return Full;
	}
	else if (HasFlush(_compoundHand))
	{
		return Flush;
	}
	if (HasStraight(_compoundHand))
	{
		return Straight;
	}
	if (HasThreeOfAKind(_compoundHand))
	{
		return ThreeOfAKind;
	}
	if (HasTwoPairs(_compoundHand))
	{
		return TwoPairs;
	}
	if (HasPair(_compoundHand))
	{
		return Pair;
	}
	else
	{
		return HightCard;
	}
}

//maps to create bools for the evaluate function
std::map<Rank, int> RankOccurences(const std::vector<Card>& compoundHand)
{
	std::map<Rank, int> occurences;

	for (auto c : compoundHand)
	{
		if (occurences.find(c.rank) == occurences.end())
		{
			occurences[c.rank] = 1;
		}
		else
		{
			occurences[c.rank]++;
		}
	}
	return occurences;
}
std::map<Suit, int> SuitOccurences(const std::vector<Card>& compoundHand)
{
	std::map<Suit, int> occurences;

	for (auto c : compoundHand)
	{
		if (occurences.find(c.suit) == occurences.end())
		{
			occurences[c.suit] = 1;
		}
		else
		{
			occurences[c.suit]++;
		}
	}
	return occurences;
}

//bools for the evaluate function
#pragma region bool
bool HasPair(const std::vector<Card>& compoundHand)
{
	const std::map<Rank, int> occurences = RankOccurences(compoundHand);
	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 2)
		{
			return true;
		}
	}
	return false;
}
bool HasTwoPairs(const std::vector<Card>& compoundHand)
{
	const std::map<Rank, int> occurences = RankOccurences(compoundHand);
	bool FoundTwoPairs = false;

	for (std::pair<enum Rank, int> p : occurences)
	{
		if (p.second == 2)
		{
			if (FoundTwoPairs == true)
			{
				return true;
			}
			else
			{
				FoundTwoPairs = true;
			}
		}
	}
	return false;
}
bool HasThreeOfAKind(const std::vector<Card>& compoundHand)
{
	const std::map<Rank, int> occurences = RankOccurences(compoundHand);

	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 3)
		{
			return true;
		}
	}
	return false;
}
bool HasFourOfAKind(const std::vector<Card>& compoundHand)
{
	const std::map<Rank, int> occurences = RankOccurences(compoundHand);

	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 4)
		{
			return true;
		}
	}
	return false;
}
bool HasStraight(const std::vector<Card>& compoundHand)
{
	std::map<Rank, int> occurrences = RankOccurences(compoundHand);
	int FirstNumber = 2;
	bool IsInOrder = true;

	for (std::pair<Rank, int> p : occurrences)
	{
		if (p.first == FirstNumber)
		{
			FirstNumber++;
		}
		else
		{
			IsInOrder = false;
		}
	}
	if (IsInOrder == true)
	{
		return  true;
	}
	else
	{
		return false;
	}
}
bool HasFlush(const std::vector<Card>& compoundHand)
{
	std::map<Suit, int> occurrences = SuitOccurences(compoundHand);
	
	for (std::pair<Suit, int> p : occurrences)
	{
		if (p.second == 5)
		{
			return true;

		}
	}
	return false;
}
bool HasFull(const std::vector<Card>& totalHand)
{
	std::map<Rank, int> occurrences = RankOccurences(totalHand);

	for (std::pair<Rank, int> p : occurrences)
	{
		if (p.second == 3)
		{
			if (p.second == 2)
			{
				return true;
			}
		}
	}
	return false;
}
bool HasStraightFlush(const std::vector<Card>& totalHand)
{
	std::map<Rank, int> Rankoccurences = RankOccurences(totalHand);
	std::map<Suit, int> Suitoccurrences = SuitOccurences(totalHand);

	int FirstNumber = 2;
	bool IsInOrder = true;

	for (std::pair<Rank, int> p : Rankoccurences)
	{
		if (p.first == FirstNumber)
		{
			FirstNumber++;
		}
		else
		{
			IsInOrder = false;
		}
	}

	for (std::pair<Suit, int> p : Suitoccurrences)
	{
		if (IsInOrder == true)
		{
			if (p.second == 5)
			{
				return  true;
			}
		}
	}
	return false;
}
#pragma endregion