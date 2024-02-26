#pragma once
#include "Card.hpp"

class BlueCard : public Card {
public:
	BlueCard(int number) : Card(number, 2, "Blue") {}
	~BlueCard() { std::cout << "Blue card destroyed\n"; }
};