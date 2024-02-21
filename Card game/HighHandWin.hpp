#include "Game.hpp"

class HighHandWin : public Game {
public:
	HighHandWin(Deck deck) : Game(deck) {}
	void announceWinner() override {
		if (!gameIsStarted_) {
			// Noget fejlhåndtering
		}
		else {
			Player* winner = players_.front();
			for (auto& player : players_) {
				if (player->totalHand() > winner->totalHand()) {
					winner = player;
				}
			}
			std::cout << "\nThe winner is: " << winner->getName() << "\n";
		}
	}
};