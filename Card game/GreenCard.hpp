#pragma once
#include "Card.hpp"

class GreenCard : public Card {
public:
	GreenCard(int number) {
		number_ = number;
		suit_ = 3;
		suitName_ = "Green";
	}
};