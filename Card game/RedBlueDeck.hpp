#pragma once
#include "Deck.hpp"

class RedBlueDeck : public Deck {
public:
	void createDeck() override {
		for (int i = 1; i <= 8; i++) {
			cards_.push_back(RedCard(i));
			cards_.push_back(BlueCard(i));
		}
	}
};