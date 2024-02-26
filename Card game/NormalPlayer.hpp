#include "IPlayer.hpp"

class NormalPlayer : public IPlayer {
public:
	NormalPlayer(std::string name) : IPlayer(name) {}
	void acceptCard(Card card) override {
		cards_.push_back(card);
	}

	~NormalPlayer() override { std::cout << "NormalPlayer destroyed\n"; }
};