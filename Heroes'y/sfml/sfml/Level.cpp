#include "Game.h"
#include "Level.h"
#include <fstream>

Level::Level()
{
}
Level::~Level()
{
	delete background;
}
void Level::Init()
{
	background = new Background;
	background->setPosition(Vector2f(0, 20));
	entities.push_back(background);

	field = new Field();
	field->setPosition(Vector2f(80, 102));
	entities.push_back(field);
	

	for (int i = 0; i < 2; i++)
	{

			knight = new Knight();
			knight->setPosition(knight->getStartPosition());
			entities.push_back(knight);

			sorcerer = new Sorcerer();
			sorcerer->setPosition(sorcerer->getStartPosition());
			entities.push_back(sorcerer);


		players[i] = new Player(knight, sorcerer);
		entities.push_back(players[i]);
	}


}

void Level::Update( float dt )
{
	for (auto& entity : entities)
	{
		entity->Update();
		if (entity->GetIsDestroyed())
		{
			pendingDestroy.push_back(entity);
		}
	}
	for (auto& toDestroy : pendingDestroy)
	{
		entities.erase(std::remove(entities.begin(), entities.end(), toDestroy), entities.end());
		delete toDestroy;
	}
	pendingDestroy.clear();
}
void Level::Render(RenderWindow* window)
{
	for (auto& entity : entities)
	{
		SpriteRenderer* spriteRenderer = entity->getRenderer();
		spriteRenderer-> Render(window, 0);
	}
}

Background* Level::GetBackground()
{
	return background;
}
