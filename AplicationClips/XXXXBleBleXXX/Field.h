#pragma once

#include "Entity.h"
#include "Unit.h"

class Field : public Entity
{
public:
	Field();
	Field(const Field &obj);
	virtual ~Field();
	void move();
	virtual void Update() override;
	Unit *unit;
	bool hasUnit;
	int ColumnIndex;
	int RowIndex;
private:
	Image *img;
	Texture *texture;
};