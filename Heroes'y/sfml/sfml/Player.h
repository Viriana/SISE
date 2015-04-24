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
	Player(string name, float spriteRotation);
	~Player();
	Unit* getPlayerUnits(int i);
	void setPlayerUnits();
	void decide(Player *opponent);
private:
	vector <Unit*> units;
	string name;
};

