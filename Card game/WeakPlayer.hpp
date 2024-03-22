#include "IPlayer.hpp"

class WeakPlayer : public IPlayer {
public:
	WeakPlayer(std::string name) : IPlayer(name){}
	void acceptCard(std::unique_ptr<Card> card) override {
		if (cards_.size() >= 3) {
			cards_.pop_back();
		}
		cards_.push_back(std::move(card));
	}

	~WeakPlayer() override { std::cout << "WeakPlayer destroyed\n"; }
};