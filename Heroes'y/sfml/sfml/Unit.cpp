
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

bool Unit::getIsSelected()
{
	return isSelected;
}

void Unit::setIsSelected(bool isSelected)
{
	this->isSelected = isSelected;
}

bool Unit::getIsAlive()
{
	return isAlive;
}

void Unit::setIsAlive(bool isAlive)
{
	this->isAlive = isAlive;
}

int Unit::getArmor()
{
	return armor;
}

void Unit::attack(Unit *unit)
{

}

int Unit::getMovementSpeed()
{
	return movementSpeed;
}

Vector2f Unit::getStartPosition()
{
	return startPosition;
}

void Unit::setStartPosition(Vector2f startPosition)
{
	this->startPosition = startPosition;
}

void Unit::setCurrentPosition(Vector2f currentPosition)
{
	this->currentPosition = currentPosition;
}

Vector2f Unit::getCurrentPosition()
{
	return currentPosition;
}