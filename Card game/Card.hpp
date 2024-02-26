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

protected:
	int number_;
	int suit_;
	std::string suitName_;
};

