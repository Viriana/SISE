#pragma once
#include "Tile.h"
class Background : public Tile
{
public:
	Background();
	~Background();
private:
	Texture *texture;
};