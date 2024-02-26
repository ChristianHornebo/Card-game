#pragma once
#include "Card.hpp"

class GreenCard : public Card {
public:
	GreenCard(int number) : Card(number, 3, "Green") {}
};