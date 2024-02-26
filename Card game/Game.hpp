#pragma once
#include <list>
#include <iostream>
#include "Player.hpp"
#include "Deck.hpp"
#include "IGametype.hpp"

class Game {
public:
	Game(Deck* deck, IGameType* gameType) : deck_(deck), gameType_(gameType) {
		gameIsStarted_ = false;
		deck_->createDeck();
		deck_->shuffle();
	}

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

	void announceWinner() {
		gameType_->announceWinner(players_);
	}

	void setGameType(IGameType* gameType) {
		if (gameType_ != nullptr) {
			delete gameType_;
		}
		gameType_ = gameType;
	}

	IGameType* getGameType() {
		return gameType_;
	}

	~Game() {
		delete gameType_;
		delete deck_;
	}

protected:
	std::list<Player*> players_;
	bool gameIsStarted_;

private:
	Deck* deck_ = nullptr;
	IGameType* gameType_ = nullptr;
	void dealCards() {
		for (auto& player : players_) {
			deck_->deal(*player, 5);
		}
	}
};