
#include "Unit.h"
#include "Field.h"


Unit::Unit()
{
	field = nullptr;
	IsDestroyed = false;
	ColumnsNumber = -1;
	RawsNumber = -1;
	strength = -1;
	range = -1;
	maxHealthPoints = -1;
	armor = -1;
	currentHealthPoints = -1;
	movementSpeed = -1;
	isSelected = false;
}

Unit::Unit(const Unit& obj)
{
	type = obj.type;
	Renderer = obj.Renderer;
	index = obj.index;
	ColumnIndex = obj.ColumnIndex;
	RowIndex = obj.RowIndex;
	field = obj.field;
	IsDestroyed = obj.IsDestroyed;
	ColumnsNumber = obj.ColumnsNumber;
	RawsNumber = obj.RawsNumber;
	strength = obj.strength;
	range = obj.range;
	maxHealthPoints = obj.maxHealthPoints;
	armor = obj.armor;
	currentHealthPoints = obj.currentHealthPoints;
	movementSpeed = obj.movementSpeed;
	isSelected = obj.isSelected;
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

void Unit::heal(Unit* unit)
{
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