#pragma once
#include "Unit.h"
#include "Sorcerer.h"
#include "Knight.h"
using namespace std;

class Player: public Entity
{
public:
	Player(Knight* knight, Sorcerer* sorcerer);
	~Player();
	Unit* getPlayerUnits(int i);
	void setPlayerUnits();
private:
	Unit *units[4];
	Knight* knight_;
	Sorcerer* sorcerer_;
};

