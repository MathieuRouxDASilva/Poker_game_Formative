#include <iostream>
#include "CardsFinish.h"
#include "Deck.h"

//main
int main()
{
	//little introduction
	std::cout << "welcome to this poker game sit down and take your cards player, just know that due to a lack of knowledge chosing doesn't affect the game thx^^\n\n\n";

	//function to crate a deck
	CreateAndBlendDeck();

	//give and show 2 cards to the player
	std::cout << "your hand : \n\n";
	std::cout << "-------------------------\n";
	HandPlayer.push_back(GiveACard());
	HandPlayer.push_back(GiveACard());
	ToString("Player", HandPlayer);
	std::cout << "-------------------------\n\n";

	//give 2 cards to the bot
	HandBot.push_back(GiveACard());
	HandBot.push_back(GiveACard());

	// Flop system (add 3 cards to the screen)
	std::cout << "3 cards on the table : \n\n";
	std::cout << "-------------------------\n";
	Table.push_back(GiveACard());
	Table.push_back(GiveACard());
	Table.push_back(GiveACard());
	ToString("Table : ", Table);
	std::cout << "-------------------------\n";

	//function that ask to the player what he wants to do (not usefull but still exist)
	ChoiceOfAction();

	//Turn system (add another card to the screen)
	Table.push_back(GiveACard());

	system("cls");
	std::cout << "your hand : \n\n";
	std::cout << "-------------------------\n";
	ToString("Player", HandPlayer);
	std::cout << "-------------------------\n\n";
	std::cout << "4 cards on the table : \n\n";
	std::cout << "-------------------------\n";
	ToString("Table : ", Table);
	std::cout << "-------------------------\n";

	ChoiceOfAction();

	//River system (add a last card to the screen)
	Table.push_back(GiveACard());

	system("cls");
	std::cout << "your hand : \n\n";
	std::cout << "-------------------------\n";
	ToString("Player", HandPlayer);
	std::cout << "-------------------------\n\n";
	std::cout << "5 cards on the table : \n\n";
	std::cout << "-------------------------\n";
	ToString("Table : ", Table);
	std::cout << "-------------------------\n";

	//function to evaluate which player has best combo
	const CardsCombo playerValue = Evaluate(HandPlayer);
	const CardsCombo botValue = Evaluate(HandBot);

	std::cout << "\n\n\n";
	std::cout << "result is :\n";
	//system to determine who win this game
	if (playerValue > botValue)
	{
		std::cout << "Player Won : " << ToString(playerValue) << std::endl;
		std::cout << "Bot : " << ToString(botValue) << std::endl;
	}
	else if (playerValue < botValue)
	{
		std::cout << "Bot Won : " << ToString(botValue) << std::endl;
		std::cout << "Player : " << ToString(playerValue) << std::endl;
	}
	else
	{
		std::cout << "SPLIT" << std::endl;
	}
}