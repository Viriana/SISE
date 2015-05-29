#include "Game.h"
#include "Level.h"
#include <fstream>

Level::Level()
{
	ColumnsNumber = 15;
	RawsNumber = 11;
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

	for (int i = 0; i < ColumnsNumber; i++)
	{
		for (int j = 0; j < RawsNumber; j++)
		{
			Field *field = new Field();
			field->setPosition(Vector2f(44.0f*i - 22.0f*(j % 2) + 80, 42.0f*j + 102));
			field->render = false;
			entities.push_back(field);
			fields.push_back(field);
		}
	}

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
		if (entity->GetIsDestroyed() || entity->isAlive == false)
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
		if (entity->render)
		{
			SpriteRenderer* spriteRenderer = entity->getRenderer();
			spriteRenderer->Render(window, 0);
		}
	}
}

Background* Level::GetBackground()
{
	return background;
}
