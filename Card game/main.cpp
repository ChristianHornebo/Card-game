#include "Game.hpp"
#include "NormalPlayer.hpp"
#include "WeakPlayer.hpp"
#include "LowHandWin.hpp"
#include "HighHandWin.hpp"
#include "RedBlueDeck.hpp"
#include "NormalDeck.hpp"

int main() {
	IDeck* deck = new NormalDeck();

	IPlayer* player1 = new NormalPlayer("Player 1");
	IPlayer* player2 = new NormalPlayer("Player 2");
	IPlayer* player3 = new WeakPlayer("Player 3");

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
		game.acceptPlayer(player1);
		game.acceptPlayer(player2);
		game.acceptPlayer(player3);
		game.start();

		std::cout << player1->showHand();
		std::cout << "Total hand: " << player1->totalHand() << "\n\n";
		std::cout << player2->showHand();
		std::cout << "Total hand: " << player2->totalHand() << "\n\n";
		std::cout << player3->showHand();
		std::cout << "Total hand: " << player3->totalHand() << "\n\n";

		game.announceWinner();
	}
	else {
		std::cout << "Invalid game type\n";
	}

	delete player3;
	delete player2;
	delete player1;
	delete deck;

	return 0;
}