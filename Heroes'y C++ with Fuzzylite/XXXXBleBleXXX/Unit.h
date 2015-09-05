#pragma once

#include "Entity.h"

using namespace std;
using namespace sf;

class Unit : public Entity
{
public:
	Unit();
	virtual ~Unit();
	virtual void Update();
	void Move(Vector2f v);
	virtual string getType();
	virtual int getStrength();
	virtual int getRange();
	virtual int getMaxHealthPoints();
	virtual int getCurrentHealthPoints();
	virtual void setCurrentHealthPoints(int damage);
	virtual int getArmor();
	virtual void attack(Unit *unit);
	virtual int getMovementSpeed();
	virtual bool getIsSelected();
	virtual void setIsSelected(bool isSelected);
	void Destroy();
	virtual void heal(Unit* unit);
	vector <float> columns;
	vector <float> raws;
	Entity *field;
private:
	bool IsDestroyed;

	int ColumnsNumber;
	int RawsNumber;
protected:
	string type;
	int strength;
	int range;
	int maxHealthPoints;
	int armor;
	int currentHealthPoints;
	int movementSpeed;
	bool isSelected;
};

