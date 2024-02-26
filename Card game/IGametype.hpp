#pragma once
#include "IPlayer.hpp"
#include <list>
#include <iostream>

class IGameType {
public:
	virtual void announceWinner(std::list<IPlayer*> players) = 0;
	virtual ~IGameType() { std::cout << "IGameType destroyed\n"; }
};