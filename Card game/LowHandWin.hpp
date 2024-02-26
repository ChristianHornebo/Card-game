#include "IGametype.hpp"

class LowHandWin : public IGameType {
public:
	void announceWinner(std::list<IPlayer*> players) override {
		IPlayer* winner = players.front();
		for (auto& player : players) {
			if (player->totalHand() < winner->totalHand()) {
				winner = player;
			}
		}
		std::cout << "The winner is: " << winner->getName() << "\n";
	}
	~LowHandWin() override { std::cout << "LowHandWin destroyed\n"; }
};