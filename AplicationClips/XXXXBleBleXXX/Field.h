#pragma once

#include "Entity.h"

class Field : public Entity
{
public:
	Field();
	virtual ~Field();
	void move();
	virtual void Update() override;
private:
	Image *img;
	Texture *texture;
};