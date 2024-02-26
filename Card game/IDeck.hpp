#pragma once
#include <vector>
#include "Card.hpp"
#include "RedCard.hpp"
#include "BlueCard.hpp"
#include "GreenCard.hpp"
#include "YellowCard.hpp"
#include "IPlayer.hpp"
#include <iostream>


class IDeck {
public:
	void deal(IPlayer &player, int numOfCards) {
		for (int i = 0; i < numOfCards; i++) {
			player.acceptCard(cards_.back());
			cards_.pop_back();
		}
	}

	virtual void createDeck() = 0;

	void shuffle() {
		srand(time(0));
		for (int i = 0; i < 50*cards_.size(); i++) {
			int pos1 = rand() % cards_.size();
			int pos2 = rand() % cards_.size();

			Card temp = cards_[pos1];
			cards_[pos1] = cards_[pos2];
			cards_[pos2] = temp;
		}
	}

	virtual ~IDeck() { std::cout << "IDeck destroyed\n"; }

protected:
	std::vector<Card> cards_;
};