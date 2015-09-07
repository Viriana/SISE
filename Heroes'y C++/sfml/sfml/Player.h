#pragma once
#include "Unit.h"
#include "Sorcerer.h"
#include "Knight.h"
#include "Healer.h"
#include "Archer.h"
#include "EventHandler.h"
using namespace std;

class Player : public Entity
{
public:
	Player(string name, float spriteRotation);
	~Player();
	void decide(Player *opponent, Unit *selectedUnit, Vector2f selectedFieldPos);

	vector <Unit*> units;
private:
	string name;
};

