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

	players.push_back(new Player("Player1", 1));
	players.push_back(new Player("Player2", -1));

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			entities.push_back(players[i]->getPlayerUnits(j));
		}
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
