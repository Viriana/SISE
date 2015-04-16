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
	virtual void attack();
	virtual int getMovementSpeed();
	bool GetIsDestroyed();
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
	
};

