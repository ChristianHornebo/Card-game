#include "Game.hpp"

class LowHandWin : public Game {
public:
	LowHandWin(Deck deck) : Game(deck) {}
	void announceWinner() override {
		if (!gameIsStarted_) {
			// Noget fejlhåndtering
		}
		else {
			Player* winner = players_.front();
			for (auto& player : players_) {
				if (player->totalHand() < winner->totalHand()) {
					winner = player;
				}
			}
			std::cout << "\nThe winner is: " << winner->getName() << "\n";
		}
	}
};