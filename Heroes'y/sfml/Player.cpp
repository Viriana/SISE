#include "Player.h"


Player::Player(Knight* knight, Sorcerer* sorcerer) :knight_(knight), sorcerer_(sorcerer)
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