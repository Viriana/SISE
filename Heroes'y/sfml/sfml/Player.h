#pragma once
#include "Unit.h"
#include "Sorcerer.h"
#include "Knight.h"
using namespace std;

class Player : public Entity
{
public:
	Player(Knight* knight, Sorcerer* sorcerer, string name);
	~Player();
	Unit* getPlayerUnits(int i);
	void setPlayerUnits();
	void decide(Player *opponent);
private:
	Unit *units[4];
	string name;
};

