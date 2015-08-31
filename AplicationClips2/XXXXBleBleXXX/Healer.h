#pragma once

#include "Unit.h"

using namespace std;
using namespace sf;

class Healer : public Unit
{
public:
	Healer();
	virtual ~Healer();
	void move();
	virtual void Update() override;
	void heal(Unit *targetUnit) override;
	//void attack(Unit *targetUnit);
private:
	Image *img;
	Texture *texture;
	int inteligence;
};

