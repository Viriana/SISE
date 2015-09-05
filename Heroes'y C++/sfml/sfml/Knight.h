#pragma once

#include "Unit.h"

using namespace std;
using namespace sf;

class Knight : public Unit
{
public:
	Knight();
	virtual ~Knight();
	void move();
	virtual void Update() override;
	void attack(Unit *targetUnit);
private:
	Image *img;
	Texture *texture;
	int meleeAccuracy;
};
