#pragma once
#include "Card.hpp"

class RedCard : public Card {
public:
	RedCard(int number) {
		number_ = number;
		suit_ = 1;
		suitName_ = "Red";
	}
};