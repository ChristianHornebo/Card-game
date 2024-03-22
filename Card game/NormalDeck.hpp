#include "IDeck.hpp"

class NormalDeck : public IDeck
{
public:
	void createDeck() override {
		for (int i = 1; i <= 8; i++) {
			cards_.push_back(std::make_unique<RedCard>(i));
			cards_.push_back(std::make_unique<BlueCard>(i));
			cards_.push_back(std::make_unique<GreenCard>(i));
			cards_.push_back(std::make_unique<YellowCard>(i));
		}
	}

	~NormalDeck() override { std::cout << "NormalDeck destroyed\n"; }
};