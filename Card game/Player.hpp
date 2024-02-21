#pragma once
#include <string>
#include <vector>
#include "Card.hpp"

class Player {
public:
	Player(std::string name) {
		name_ = name;	
	}

	virtual void acceptCard(Card card) {
		cards_.push_back(card);
	}

	int totalHand() {
		int total = 0;
		for (auto& card : cards_) {
			total += card.getValue();
		}
		return total;
	}

	std::string showHand() {
		std::string hand = name_ + " hand:\n";
		for (auto& card : cards_) {
			hand += card.displayCard() + "\n";
		}
		return hand;
	}

	std::string getName() {
		return name_;
	}

protected:
	std::vector<Card> cards_;

private:
	std::string name_;
};