#include <algorithm>
#include "Entity.h"

Entity::Entity()
{
	IsDestroyed = false;
	render = true;
	isAlive = true;
	inRange = false;
	RowIndex = -1;
	ColumnIndex = -1;
	index = -1;
}

Entity::Entity(const Entity& obj)
{
	type = obj.type;
	Renderer = obj.Renderer;
	index = obj.index;
	ColumnIndex = obj.ColumnIndex;
	RowIndex = obj.RowIndex;
	render = obj.render;
	isAlive = obj.isAlive;
	inRange = obj.inRange;
	IsDestroyed = obj.IsDestroyed;
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