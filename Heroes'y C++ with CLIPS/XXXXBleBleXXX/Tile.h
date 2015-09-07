#pragma once
#include "Entity.h"

class Tile : public Entity

{
public:
	Tile();
	virtual ~Tile();
	virtual bool Blocking();
	virtual bool CanBeDestroyed();

};