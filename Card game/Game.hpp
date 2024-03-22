#pragma once
#include <list>
#include <iostream>
#include "IPlayer.hpp"
#include "IDeck.hpp"
#include "IGametype.hpp"

class Game {
public:
	Game(std::unique_ptr<IDeck> deck, std::unique_ptr<IGameType> gameType) 
		: deck_(std::move(deck)), gameType_(std::move(gameType)) {
		gameIsStarted_ = false;
		deck_->createDeck();
		deck_->shuffle();
	}

	void acceptPlayer(std::shared_ptr<IPlayer> player) {
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

	void setGameType(std::unique_ptr<IGameType> gameType) {
		gameType_ = std::move(gameType);
	}

	const std::unique_ptr<IGameType>& getGameType() {
		return gameType_;
	}

	~Game() {
		std::cout << "Game destroyed\n";
	}

protected:
	std::vector<std::shared_ptr<IPlayer>> players_;
	bool gameIsStarted_;

private:
	std::unique_ptr<IDeck> deck_;
	std::unique_ptr<IGameType> gameType_;

	void dealCards() {
		for (auto& player : players_) {
			deck_->deal(*player, 5);
		}
	}
};