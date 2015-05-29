#include <algorithm>
#include "Entity.h"

Entity::Entity() :
IsDestroyed(false)
{
	render = true;
	isAlive = true;
}
Entity::~Entity()
{
}
void Entity::setPosition(Vector2f position)
{
	Sprite& sprite = Renderer.Sprite;
	sprite.setPosition( position );
}

SpriteRenderer* Entity::getRenderer()
{
	return &Renderer;
}

void Entity::Update()
{
}

void Entity::Move(Vector2f v)
{
	Renderer.Move( v );
}

Vector2f Entity::GetPosition()
{
	return getRenderer()-> GetPosition();
}

string Entity::getType()
{
	return type;
}

bool Entity::GetIsDestroyed()
{
	return IsDestroyed;
}

void Entity::Destroy()
{
	IsDestroyed = true;
}