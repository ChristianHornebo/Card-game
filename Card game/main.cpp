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
	

	std::cout << "Gametype: High or Low? ";
	std::string gameTypeChosen = "";
	std::cin >> gameTypeChosen;
	Game game(deck, nullptr);

	if (gameTypeChosen == "high" || gameTypeChosen == "High") {
		game.setGameType(new HighHandWin);
	}
	else if (gameTypeChosen == "low" || gameTypeChosen == "Low") {
		game.setGameType(new LowHandWin);
	}

	if(game.getGameType() != nullptr) {
		game.acceptPlayer(&player1);
		game.acceptPlayer(&player2);
		game.acceptPlayer(&player3);
		game.start();

		std::cout << player1.showHand();
		std::cout << "Total hand: " << player1.totalHand() << "\n\n";
		std::cout << player2.showHand();
		std::cout << "Total hand: " << player2.totalHand() << "\n\n";
		std::cout << player3.showHand();
		std::cout << "Total hand: " << player3.totalHand() << "\n\n";

		game.announceWinner();
	}
	else {
		std::cout << "Invalid game type\n";
	}

	return 0;
}