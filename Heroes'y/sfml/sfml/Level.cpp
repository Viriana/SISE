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
			Vector2f fieldPosition (44.0f*i - 22.0f*(j % 2) + 80, 42.0f*j + 102);
			field->setPosition(fieldPosition);
			fieldsPositions.push_back(fieldPosition);
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
			entities.push_back(players[i]->units[j]);

			if (players[i]->units[j]->getType() == "Knight")
			{
				Entity *field1 = new Entity();
				if (i == 0)
				{
					field1->setPosition(fieldsPositions[1]);
					fields[1]->unit = players[i]->units[j];
				}
				else
				{
					field1->setPosition(fieldsPositions[155]);
					fields[155]->unit = players[i]->units[j];
				}

				players[i]->units[j]->field = field1;
				fields[1]->hasUnit = true;
				fields[155]->hasUnit = true;
			}
			else if (players[i]->units[j]->getType() == "Sorcerer")
			{
				Entity *field1 = new Entity();

				if (i == 0)
				{
					field1->setPosition(fieldsPositions[4]);
					fields[4]->unit = players[i]->units[j];
				}
				else
				{
					field1->setPosition(fieldsPositions[158]);
					fields[158]->unit = players[i]->units[j];
				}
					
				players[i]->units[j]->field = field1;
				fields[4]->hasUnit = true;
				fields[158]->hasUnit = true;
			}
			else if (players[i]->units[j]->getType() == "Archer")
			{
				Entity *field1 = new Entity();
				if (i == 0)
				{
					field1->setPosition(fieldsPositions[7]);
					fields[7]->unit = players[i]->units[j];
				}
				else
				{
					field1->setPosition(fieldsPositions[161]);
					fields[161]->unit = players[i]->units[j];
				}
					
				players[i]->units[j]->field = field1;
				fields[7]->hasUnit = true;
				fields[161]->hasUnit = true;
			}
			else if (players[i]->units[j]->getType() == "Healer")
			{
				Entity *field1 = new Entity();
				if (i == 0)
				{
					field1->setPosition(fieldsPositions[10]);
					fields[10]->unit = players[i]->units[j];
				}
				else
				{
					field1->setPosition(fieldsPositions[164]);
					fields[164]->unit = players[i]->units[j];
				}

				players[i]->units[j]->field = field1;
				fields[10]->hasUnit = true;
				fields[164]->hasUnit = true;
			}
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
		players[Game->playerTurn]->units.erase(std::remove(players[Game->playerTurn]->units.begin(), players[Game->playerTurn]->units.end(), toDestroy), players[Game->playerTurn]->units.end());
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
			Game->hud->WriteLine(entity->message);
		}
	}
}

Background* Level::GetBackground()
{
	return background;
}
