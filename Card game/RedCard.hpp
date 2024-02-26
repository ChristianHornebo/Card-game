#pragma once
#include "Card.hpp"

class RedCard : public Card {
public:
	RedCard(int number) : Card(number, 1, "Red") {}
};