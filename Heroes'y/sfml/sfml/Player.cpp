#include "Player.h"


Player::Player(string name, float spriteRotation)
{
	this->name = name;

	units.push_back(new Knight());
	units.push_back(new Sorcerer());
	units.push_back(new Healer());
	units.push_back(new Archer());

	for (int i = 0; i < units.size(); i++)
	{
		units[i]->Renderer.SetScale(spriteRotation, 1.0f);

		if (spriteRotation == -1)
		{
			units[i]->setPosition(Vector2f(units[i]->GetPosition().x + 685.0f, units[i]->GetPosition().y));
		}
	}
}


Player::~Player()
{
}

void Player::decide(Player *opponent, Unit *selectedUnit, Vector2f selectedFieldPos)
{
	selectedUnit->setPosition(Vector2f(selectedFieldPos.x - 15, selectedFieldPos.y - 65));
}