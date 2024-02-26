#pragma once
#include <list>
#include <iostream>
#include "IPlayer.hpp"
#include "IDeck.hpp"
#include "IGametype.hpp"

class Game {
public:
	Game(IDeck* deck, IGameType* gameType) : deck_(deck), gameType_(gameType) {
		gameIsStarted_ = false;
		deck_->createDeck();
		deck_->shuffle();
	}

	void acceptPlayer(IPlayer* player) {
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
		std::cout << "Game destroyed\n";
	}

protected:
	std::list<IPlayer*> players_;
	bool gameIsStarted_;

private:
	IDeck* deck_ = nullptr;
	IGameType* gameType_ = nullptr;
	void dealCards() {
		for (auto& player : players_) {
			deck_->deal(*player, 5);
		}
	}
};