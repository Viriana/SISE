#include "Level.h"
#include "Game.h"

Game::Game():
level(nullptr),
window(VideoMode(800, 600, 32), "Heroes tsy"),
view(Vector2f(400.0f, 300.0f), Vector2f(800.0f, 600.0f))
{
	window.setFramerateLimit(30);
	window.setView(view);
	window.setKeyRepeatEnabled(false);
	globalTime = 0.0f;
	level = new Level();
	level->Game = this;
	level->Init();
	flag = false;
	playerTurn = 0;
	hud = new Hud(view, window);
}

Game::~Game()
{
	delete level;
}

bool Game::OpponentUnit(Unit* unit)
{
	for (int i = 0; i < level->players[!playerTurn]->units.size(); i++)
	{
		if (unit == level->players[!playerTurn]->units[i])
		{
			return true;
		}
	}
	return false;
}

void Game::play()
{
	//cout << "Player" << playerTurn + 1 << " turn\n\n";
	hud->WriteGameState("Player" + to_string(playerTurn + 1) + " turn\n\n");

	while (window.isOpen())
	{
		eventHandler.readEvents(window);
		
		float time = clock.restart().asSeconds();
		globalTime = globalTime + time;
		Update(time);
		window.clear();
		if (level != nullptr)
		{
			level-> Render( &window );
		}
		hud->display(playerTurn);
		window.display();


		selectedFieldIndex = 0;
		previousUnitIndex = 0;
		
		if (eventHandler.unitSelected && !flag)
		{
			level->players[!playerTurn]->units[previousUnitIndex]->message = "";
			selectedUnitIndex = selectedUnit(eventHandler.mousePosition);
			previousUnitIndex = selectedUnitIndex;

			if (selectedUnitIndex != -1)
			{
				//cout << "Selected  " << level->players[playerTurn]->units[selectedUnitIndex]->getType() << endl;
				hud->WriteGameState("Selected  " + level->players[playerTurn]->units[selectedUnitIndex]->getType());
				flag = true;
				DrawRange(level->players[playerTurn]->units[selectedUnitIndex]);
			}
			else
			{
				//cout << "Wrong select! Try again" << endl;
				hud->WriteGameState("Wrong select! Try again");
				eventHandler.unitSelected = false;
				eventHandler.fieldSelected = false;
				eventHandler.numberOfClicks = 0;
			}
		}

		if (eventHandler.fieldSelected && eventHandler.unitSelected)
		{
			selectedFieldPos = selectedField(eventHandler.mousePosition, selectedFieldIndex);

			for each (Field *field in level->fields)
			{
				if (field == level->players[playerTurn]->units[selectedUnitIndex]->field)
				{
					field->hasUnit = false;
					break;
				}
			}

			bool fieldExist = false;
			if (selectedFieldPos != Vector2f(0, 0))
			{
				fieldExist = true;
			}

			bool fieldHasUnit = false;
			if (level->fields[selectedFieldIndex]->hasUnit)
			{
				fieldHasUnit = true;
			}

			bool fieldInRange = false;
			if (level->fields[selectedFieldIndex]->inRange)
			{
				fieldInRange = true;
			}

			if (fieldExist)
			{
				if (fieldInRange)
				{
					if (!fieldHasUnit)
					{
						level->players[playerTurn]->units[selectedUnitIndex]->field = level->fields[selectedFieldIndex];
						//cout << "Selected field x: " << selectedFieldPos.x << ", y:" << selectedFieldPos.y << endl;
						level->fields[selectedFieldIndex]->unit = level->players[playerTurn]->units[selectedUnitIndex];

						selectedFieldPos = level->fieldsPositions[selectedFieldIndex];

						if (playerTurn == 1)
						{
							selectedFieldPos.x = selectedFieldPos.x + 55.0f;
						}
						level->players[playerTurn]->decide(level->players[!playerTurn], level->players[playerTurn]->units[selectedUnitIndex], selectedFieldPos);

						level->fields[selectedFieldIndex]->hasUnit = true;
					}
					else
					{
						if (OpponentUnit(level->fields[selectedFieldIndex]->unit))
						{
							for (int i = 0; i < level->players[!playerTurn]->units.size(); i++)
							{
								if (level->fields[selectedFieldIndex] == level->players[!playerTurn]->units[i]->field)
								{

									if (playerTurn == 0)
									{
										selectedFieldIndex -= 11;
									}
									else
									{
										selectedFieldIndex += 11;
									}

									level->players[playerTurn]->units[selectedUnitIndex]->field = level->fields[selectedFieldIndex];
									level->fields[selectedFieldIndex]->unit = level->players[playerTurn]->units[selectedUnitIndex];

									selectedFieldPos = level->fieldsPositions[selectedFieldIndex];

									if (playerTurn == 1)
									{
										selectedFieldPos.x = selectedFieldPos.x + 55.0f;
									}
									level->players[playerTurn]->decide(level->players[!playerTurn], level->players[playerTurn]->units[selectedUnitIndex], selectedFieldPos);

									level->fields[selectedFieldIndex]->hasUnit = true;

									level->players[playerTurn]->units[selectedUnitIndex]->attack(level->players[!playerTurn]->units[i]);

									break;
								}
							}
						}

						else
						{

							if (level->players[playerTurn]->units[selectedUnitIndex]->getType() != "Healer")
							{
								hud->WriteGameState("There is already UR unit!");
								eventHandler.fieldSelected = false;
								eventHandler.numberOfClicks = 1;
							}

							else
							{
								level->players[playerTurn]->units[selectedUnitIndex]->heal(level->fields[selectedFieldIndex]->unit);
							}
						}

					}

				}
				else
				{
					if (level->players[playerTurn]->units[selectedUnitIndex]->getType() != "Healer")
					{
						hud->WriteGameState("Field out of range!");
						eventHandler.fieldSelected = false;
						eventHandler.numberOfClicks = 1;
					}

					else
					{
						level->players[playerTurn]->units[selectedUnitIndex]->heal(level->fields[selectedFieldIndex]->unit);
					}
				}
			}
			else
			{
				//cout << "Wrong select! Try again" << endl;
				hud->WriteGameState("There is no such field!");
				eventHandler.fieldSelected = false;
				eventHandler.numberOfClicks = 1;
			}
		}

		if (selectedFieldPos != Vector2f(0, 0) && selectedUnitIndex != -1 && eventHandler.fieldSelected && eventHandler.unitSelected)
		{
			for each (Entity *field in level->fields)
			{
				field->render = false;
				//field->inRange = false;
			}

			eventHandler.fieldSelected = false;
			eventHandler.unitSelected = false;
			flag = false;
			playerTurn = !playerTurn;
			//cout << "Player" << playerTurn + 1 << " Turn\n\n";
			hud->WriteGameState("Player" + to_string(playerTurn + 1) + " turn\n\n");
		}
	}
}

void Game::Update(float &time)
{
	if (level != nullptr)
	{
		level->Update(time);
	}
}

int Game::selectedUnit(Vector2f mousePosition)
{
	int cursorPrecision = 1;
	FloatRect cursorRect(mousePosition.x, mousePosition.y, static_cast<float>(cursorPrecision), static_cast<float>(cursorPrecision));

	for (int j = 0; j < level->players[playerTurn]->units.size(); j++)
	{
		FloatRect unitSpriteRect = level->players[playerTurn]->units[j]->getRenderer()->GetBounds();

		if (unitSpriteRect.intersects(cursorRect))
		{
			return j;
		}
	}

	return -1;
}

Vector2f Game::selectedField(Vector2f mousePosition, int &index)
{
	for (int i = 0; i < level->ColumnsNumber*level->RawsNumber; i++)
	{
		if (level->fields[i]->getRenderer()->GetBounds().contains(mousePosition))
		{
			index = i;
			return level->fields[i]->GetPosition();
		}
	}
	return Vector2f(0, 0);
}

void Game::DrawRange(Unit *unit)
{
	for (int i = 0; i < level->fields.size(); i++)
	{
		float distance = sqrt((pow((unit->field->GetPosition().x - level->fields[i]->GetPosition().x), 2) +
			pow((unit->field->GetPosition().y - level->fields[i]->GetPosition().y), 2)));

		//float distance = sqrt((pow((unit->GetPosition().x - level->fields[i]->GetPosition().x), 2) +
			//pow((unit->GetPosition().y - level->fields[i]->GetPosition().y), 2)));

		if (distance < unit->getMovementSpeed() * 44.0f + 12.0f)
		{
			if (level->fields[i]->hasUnit == false)
			{
				level->fields[i]->render = true;
			}
			level->fields[i]->inRange = true;
		}
	}
}