#pragma once
#include "Card.hpp"

class YellowCard : public Card {
public:
	YellowCard(int number) {
		number_ = number;
		suit_ = 4;
		suitName_ = "Yellow";
	}
};