#pragma once
#include "Card.hpp"

class BlueCard : public Card {
public:
	BlueCard(int number) {
		number_ = number;
		suit_ = 2;
		suitName_ = "Blue";
	}
};