#pragma once
#include "Unit.h"
#include "Sorcerer.h"
#include "Knight.h"
#include "Healer.h"
using namespace std;

class Player: public Entity
{
public:
	Player(Knight* knight, Sorcerer* sorcerer, Healer* healer);
	~Player();
	Unit* getPlayerUnits(int i);
	void setPlayerUnits();
private:
	Unit *units[4];
	Knight* knight_;
	Sorcerer* sorcerer_;
	Healer* healer_;
};

