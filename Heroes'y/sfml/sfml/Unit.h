#pragma once

#include "Entity.h"

using namespace std;
using namespace sf;

class Unit : public Entity
{
public:
	Unit();
	virtual ~Unit();

	virtual void setPosition(sf::Vector2f position);
	virtual void Update();
	virtual SpriteRenderer* getRenderer();
	void Move(Vector2f v);
	Vector2f GetPosition();
	virtual string getType();
	virtual int getStrength();
	virtual int getRange();
	virtual int getMaxHealthPoints();
	virtual int getCurrentHealthPoints();
	virtual void setCurrentHealthPoints(int damage);
	virtual int getArmor();
	virtual void attack(Unit *unit);
	virtual int getMovementSpeed();
	virtual Vector2f getStartPosition();
	virtual void setStartPosition(Vector2f startPosition);
	virtual void setCurrentPosition(Vector2f currentPosition);
	virtual Vector2f getCurrentPosition();
	virtual bool getIsSelected();
	virtual void setIsSelected(bool isSelected);
	bool getIsAlive();
	void setIsAlive(bool isAlive);
	void Destroy();

private:
	bool IsDestroyed;
protected:
	SpriteRenderer Renderer;
	string type;
	int strength;
	int range;
	int maxHealthPoints;
	int armor;
	int currentHealthPoints;
	int movementSpeed;
	bool isSelected;
	bool isAlive;
	Vector2f currentPosition;
	Vector2f startPosition;


};

