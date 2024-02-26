#include "IPlayer.hpp"

class WeakPlayer : public IPlayer {
public:
	WeakPlayer(std::string name) : IPlayer(name){}
	void acceptCard(Card card) override {
		if (cards_.size() == 3) {
			cards_.pop_back();
		}
		cards_.push_back(card);
	}

	~WeakPlayer() override { std::cout << "WeakPlayer destroyed\n"; }
};