#pragma once
#include "Card.hpp"

class YellowCard : public Card {
public:
	YellowCard(int number) : Card(number, 4, "Yellow") {}
};