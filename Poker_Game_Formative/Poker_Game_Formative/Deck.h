#pragma once
#include <string>
#include <vector>
//enums for the rank/suit
enum Rank
{
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace
};
enum Suit
{
	Hearts,
	Spades,
	Diamonds,
	Clubs
};

//struct of this programm
struct Card
{
	Rank rank;
	Suit suit;
};

//all the differents vectors to show cards to the player
std::string ToString(Card _card);
std::string ToString(Rank _rank);
std::string ToString(Suit _suit);

//all the vectors that stack the data of the differents cards
extern std::vector<Card> Deck;
extern std::vector<Card> Table;
extern std::vector<Card> HandPlayer;
extern std::vector<Card> HandBot;

//all the differents function of the first part of this programm
void CreateAndBlendDeck();
void ToString(std::string _deckName, std::vector<Card> _deck);
void ChoiceOfAction();
Card GiveACard();