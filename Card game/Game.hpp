#pragma once
#include <list>
#include <iostream>
#include "Player.hpp"
#include "Deck.hpp"

class Game {
public:
	Game() : gameIsStarted_(false) {}
	Game(Deck deck) : deck_(deck), gameIsStarted_(false) {}
	void acceptPlayer(Player* player) {
		if (!gameIsStarted_) {
			players_.push_back(player);
		}
		else {
			// Noget fejlhåndtering
		}

	}

	void start() {
		dealCards();
		gameIsStarted_ = true;
	}

	virtual void announceWinner() = 0;

protected:
	std::list<Player*> players_;
	bool gameIsStarted_;

private:
	Deck deck_;
	void dealCards() {
		for (auto& player : players_) {
			deck_.deal(*player, 5);
		}
	}
};