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
	LowHandWin lowGame(deck);
	HighHandWin highGame(deck);
	game = &highGame;
	// game = &lowGame;
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

	return 0;
}