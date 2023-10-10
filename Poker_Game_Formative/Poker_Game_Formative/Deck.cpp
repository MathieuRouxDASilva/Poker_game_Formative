#include "Deck.h"
#include <iostream>
#include <random>

std::vector<Card> Deck;
std::vector<Card> Table;
std::vector<Card> HandPlayer;
std::vector<Card> HandBot;

//function to create/blend a deck
void CreateAndBlendDeck()
{
	for (int r = Rank::Two; r <= Rank::Ace; r++)
	{
		for (int s = Suit::Hearts; s <= Suit::Clubs; s++)
		{
			Card newCard;
			newCard.rank = (Rank)r;
			newCard.suit = (Suit)s;
			Deck.emplace_back(newCard);
		}
	}
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(Deck.begin(), Deck.end(), g);
}

//function to give a player a choice
void ChoiceOfAction()
{
	char Choice;
	int bet;
	std::cout << "what do you want to do next ?\n";
	std::cout << "you can bet [b] / check [c] / go to bed [g]\n";
	std::cin >> Choice;

	switch (Choice)
	{
	case 'b':
		std::cout << "how much do you want to bet ?\n";
		std::cin >> bet;
		break;
	case 'c':
		std::cout << "you've checked\n\n";
		break;
	case 'g':
		std::cout << "you give up already mhmm ok \n\n";
		break;
	default:
		std::cout << "wrong answer, please try again\n\n";
	}
}

//function to give a card
Card GiveACard()
{
	Card cardADonner{ Rank(-1), Suit(-1) };
	if (Deck.size() > 0)
	{
		cardADonner = Deck.at(0);
		Deck.erase(Deck.begin());
	}
	return cardADonner;
}

//Set of function to translate enums to actual radable stuff for the player
#pragma region ToString
void ToString(std::string _deckName, std::vector<Card> _deck)
{
	for (Card c : _deck)
	{
		std::cout << ToString(c) << std::endl;
	}
}

std::string ToString(Card _card)
{
	return ToString(_card.rank) + " of " + ToString(_card.suit);
}

std::string ToString(Rank _rank)
{
	switch (_rank)
	{
	case Two:
		return "Two";
		break;
	case Three:
		return "Three";
		break;
	case Four:
		return "Four";
		break;
	case Five:
		return "Five";
		break;
	case Six:
		return "Six";
		break;
	case Seven:
		return "Seven";
		break;
	case Eight:
		return "Eight";
		break;
	case Nine:
		return "Nine";
		break;
	case Ten:
		return "Ten";
		break;
	case Jack:
		return "Jack";
		break;
	case Queen:
		return "Queen";
		break;
	case King:
		return "King";
		break;
	case Ace:
		return "Ace";
		break;
	default:
		return "no_rank";
	}


}

std::string ToString(Suit _suit)
{
	switch (_suit)
	{
	case Hearts:
		return "Hearts";
		break;
	case Spades:
		return "Spades";
		break;
	case Diamonds:
		return "Diamonds";
		break;
	case Clubs:
		return "Clubs";
		break;
	default:
		return "_no_suit";
	}
}
#pragma endregion