#pragma once

#include "Unit.h"

using namespace std;
using namespace sf;

class Archer : public Unit
{
public:
	Archer();
	virtual ~Archer();
	void move();
	virtual void Update() override;
	void attack(Unit *targetUnit);
private:
	Image *img;
	Texture *texture;
	int dexterity;
};
