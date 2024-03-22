#include "Game.hpp"
#include "NormalPlayer.hpp"
#include "WeakPlayer.hpp"
#include "LowHandWin.hpp"
#include "HighHandWin.hpp"
#include "RedBlueDeck.hpp"
#include "NormalDeck.hpp"

int main() {
	std::unique_ptr<IDeck> deck = std::make_unique<RedBlueDeck>();

	std::shared_ptr<IPlayer> player1 = std::make_shared<NormalPlayer>("Player 1");
	std::shared_ptr<IPlayer> player2 = std::make_shared<NormalPlayer>("Player 2");
	std::shared_ptr<IPlayer> player3 = std::make_shared<WeakPlayer>("Player 3");

	std::cout << "Gametype: High or Low? ";
	std::string gameTypeChosen = "";
	std::cin >> gameTypeChosen;
	Game game(std::move(deck), nullptr);

	if (gameTypeChosen == "high" || gameTypeChosen == "High") {
		game.setGameType(std::make_unique<HighHandWin>());
	}
	else if (gameTypeChosen == "low" || gameTypeChosen == "Low") {
		game.setGameType(std::make_unique<LowHandWin>());
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

	return 0;
}