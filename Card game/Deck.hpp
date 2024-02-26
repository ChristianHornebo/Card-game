#pragma once
#include <vector>
#include "Card.hpp"
#include "RedCard.hpp"
#include "BlueCard.hpp"
#include "GreenCard.hpp"
#include "YellowCard.hpp"
#include "Player.hpp"
#include <iostream>


class Deck {
public:
	void deal(Player &player, int numOfCards) {
		for (int i = 0; i < numOfCards; i++) {
			player.acceptCard(cards_.back());
			cards_.pop_back();
		}
	}

	virtual void createDeck() {
		for (int i = 1; i <= 8; i++) {
			cards_.push_back(RedCard(i));
			cards_.push_back(BlueCard(i));
			cards_.push_back(GreenCard(i));
			cards_.push_back(YellowCard(i));
		}
	}

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

protected:
	std::vector<Card> cards_;
};