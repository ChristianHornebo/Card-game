#include "IDeck.hpp"

class NormalDeck : public IDeck
{
public:
	void createDeck() override {
		for (int i = 1; i <= 8; i++) {
			cards_.push_back(RedCard(i));
			cards_.push_back(BlueCard(i));
			cards_.push_back(GreenCard(i));
			cards_.push_back(YellowCard(i));
		}
	}

	~NormalDeck() override { std::cout << "NormalDeck destroyed\n"; }
};