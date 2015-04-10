#pragma once

#include "Entity.h"

class Knight : public Entity
{
public:
	Knight();
	virtual ~Knight();
	void move();
	virtual void Update() override;
private:
	Image *img;
	Texture *texture;
};