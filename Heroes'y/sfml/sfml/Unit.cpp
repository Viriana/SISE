
#include "Unit.h"


Unit::Unit()
{
}


Unit::~Unit()
{
}

void Unit::Update()
{
}

void Unit::Move(Vector2f v)
{
	Renderer.Move(v);
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