#pragma once
#include "Player.hpp"
#include <list>

class IGameType {
public:
	virtual void announceWinner(std::list<Player*> players) = 0;
};