#pragma once
#include "IDeck.hpp"

class RedBlueDeck : public IDeck {
public:
	void createDeck() override {
		for (int i = 1; i <= 8; i++) {
			cards_.push_back(new RedCard(i));
			cards_.push_back(new BlueCard(i));
		}
	}

	~RedBlueDeck() override { std::cout << "RedBlueDeck destroyed\n"; }
};