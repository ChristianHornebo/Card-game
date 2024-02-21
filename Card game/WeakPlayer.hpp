#include "Player.hpp"

class WeakPlayer : public Player {
public:
	WeakPlayer(std::string name) : Player(name){}
	void acceptCard(Card card) override {
		if (cards_.size() == 3) {
			cards_.pop_back();
		}
		cards_.push_back(card);
	}
};