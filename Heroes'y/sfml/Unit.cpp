
#include "Unit.h"


Unit::Unit()
{
}


Unit::~Unit()
{
}

void Unit::setPosition(Vector2f position)
{
	Sprite& sprite = Renderer.Sprite;
	sprite.setPosition(position);
}
void Unit::Update()
{
}

SpriteRenderer* Unit::getRenderer()
{
	return &Renderer;
}


void Unit::Move(Vector2f v)
{
	Renderer.Move(v);
}

Vector2f Unit::GetPosition()
{
	return getRenderer()->GetPosition();
}
string Unit::getType()
{
	return type;
}

int Unit::getStrength()
{
	return strength;
}

int Unit::getRange()
{
	return range;
}

int Unit::getMaxHealthPoints()
{
	return maxHealthPoints;
}

int Unit::getCurrentHealthPoints()
{
	return currentHealthPoints;
}

void Unit::setCurrentHealthPoints(int damage)
{
	currentHealthPoints = currentHealthPoints - damage;
}

int Unit::getArmor()
{
	return armor;
}

void Unit::attack()
{

}

int Unit::getMovementSpeed()
{
	return movementSpeed;
}