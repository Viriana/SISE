#pragma once

#include "Entity.h"
#include "Unit.h"

class Field : public Entity
{
public:
	Field();
	virtual ~Field();
	void move();
	virtual void Update() override;
	Unit *unit;
	bool hasUnit;
private:
	Image *img;
	Texture *texture;
};