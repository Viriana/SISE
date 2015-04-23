#include "Player.h"


Player::Player(Knight* knight, Sorcerer* sorcerer, Healer* healer) :knight_(knight), sorcerer_(sorcerer), healer_(healer)
{

}


Player::~Player()
{
}

Unit* Player::getPlayerUnits(int i)
{
	return units[i];
}

void Player::setPlayerUnits()
{

}