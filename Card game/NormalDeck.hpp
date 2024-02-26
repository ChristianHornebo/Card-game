#include "IDeck.hpp"

class NormalDeck : public IDeck
{
public:
	void createDeck() override {
		for (int i = 1; i <= 8; i++) {
			cards_.push_back(new RedCard(i));
			cards_.push_back(new BlueCard(i));
			cards_.push_back(new GreenCard(i));
			cards_.push_back(new YellowCard(i));
		}
	}

	~NormalDeck() override { std::cout << "NormalDeck destroyed\n"; }
};