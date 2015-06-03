#pragma once

#include <SFML/Graphics.hpp>

#include "SpriteRenderer.h"
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class Entity
{
public:
    Entity();
	virtual ~Entity();
	virtual void setPosition(sf::Vector2f position);
	virtual void Update();
	virtual SpriteRenderer* getRenderer();
	void Move(Vector2f v);
	Vector2f GetPosition();
	virtual string getType();
	bool GetIsDestroyed();
	void Destroy();
	SpriteRenderer Renderer;
	bool render;
	bool isAlive;
private:
	bool IsDestroyed;
protected:
	string type;
};