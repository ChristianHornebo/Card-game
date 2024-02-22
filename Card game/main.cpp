#include "BlueCard.hpp"
#include <iostream>
#include "Deck.hpp"
#include "Game.hpp"
#include "WeakPlayer.hpp"
#include "LowHandWin.hpp"
#include "HighHandWin.hpp"

int main() {
	Deck deck;

	Player player1("Player 1");
	Player player2("Player 2");
	Player player3("Player 3");
	
	Game* game;

	std::cout << "Gametype: High or Low? ";
	std::string gameType = "";
	std::cin >> gameType;
	if(gameType == "high" || gameType == "High")
		game = new HighHandWin(deck);
	else if(gameType == "low" || gameType == "Low")
		game = new LowHandWin(deck);
	else
		game = new HighHandWin(deck);

	game->acceptPlayer(&player1);
	game->acceptPlayer(&player2);
	game->acceptPlayer(&player3);
	game->start();

	std::cout << player1.showHand();
	std::cout << "Total hand: " << player1.totalHand() << "\n\n";
	std::cout << player2.showHand();
	std::cout << "Total hand: " << player2.totalHand() << "\n\n";
	std::cout << player3.showHand();
	std::cout << "Total hand: " << player3.totalHand() << "\n\n";

	game->announceWinner();

	delete game;

	return 0;
}