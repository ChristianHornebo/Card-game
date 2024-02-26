#include "IGametype.hpp"

class HighHandWin : public IGameType {
public:
	void announceWinner(std::list<Player*> players) override {
		Player* winner = players.front();
		for (auto& player : players) {
			if (player->totalHand() > winner->totalHand()) {
				winner = player;
			}
		}
		std::cout << "\nThe winner is: " << winner->getName() << "\n";	
	}
};