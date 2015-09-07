#include "Tile.h"
#include "Game.h"

Tile::Tile()
{
}
Tile::~Tile()
{
}

bool Tile::CanBeDestroyed()
{
	return false;
}

bool Tile::Blocking()
{
	return false;
}