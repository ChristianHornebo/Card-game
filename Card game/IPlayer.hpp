#pragma once
#include <string>
#include <vector>
#include "Card.hpp"
#include <iostream>

class IPlayer {
public:
	IPlayer(std::string name) {
		name_ = name;	
	}

	virtual void acceptCard(std::unique_ptr<Card> card) = 0;

	int totalHand() {
		int total = 0;
		for (auto& card : cards_) {
			total += card->getValue();
		}
		return total;
	}

	std::string showHand() {
		std::string hand = name_ + " hand:\n";
		for (auto& card : cards_) {
			hand += card->displayCard() + "\n";
		}
		return hand;
	}

	std::string getName() {
		return name_;
	}

	virtual ~IPlayer() { 
		std::cout << "IPlayer destroyed\n"; 
	}

protected:
	std::vector<std::unique_ptr<Card>> cards_;

private:
	std::string name_;
};