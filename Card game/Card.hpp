#pragma once
#include <string>
#include <iostream>

class Card {
public:
	int getValue() {
		return number_ * suit_;
	}

	std::string displayCard() {
		return suitName_ + " " + std::to_string(number_);
	}

	~Card() { std::cout << "Card destroyed\n"; }

protected:
	int number_;
	int suit_;
	std::string suitName_;
};

