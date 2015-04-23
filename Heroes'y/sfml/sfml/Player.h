#pragma once
#include "Unit.h"
#include "Sorcerer.h"
#include "Knight.h"
#include "Healer.h"
#include "Archer.h"
using namespace std;

class Player : public Entity
{
public:
	Player(Knight* knight, Sorcerer* sorcerer, Healer* healer, Archer* archer, string name);
	~Player();
	Unit* getPlayerUnits(int i);
	void setPlayerUnits();
	void decide(Player *opponent);
private:
	Unit *units[4];
	string name;
};

