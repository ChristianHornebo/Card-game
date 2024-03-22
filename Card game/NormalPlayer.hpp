#include "IPlayer.hpp"

class NormalPlayer : public IPlayer {
public:
	NormalPlayer(std::string name) : IPlayer(name) {}
	void acceptCard(std::unique_ptr<Card> card) override {
		cards_.push_back(std::move(card));
	}

	~NormalPlayer() override { std::cout << "NormalPlayer destroyed\n"; }
};