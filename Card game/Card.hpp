#pragma once
#include <string>
#include <iostream>

class Card {
public:
	Card(int number, int suit, std::string suitName) : number_(number), suit_(suit), suitName_(suitName) {}
	
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

