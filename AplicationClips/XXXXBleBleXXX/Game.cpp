#include "Level.h"
#include "Game.h"

Game::Game() :
window(VideoMode(800, 600, 32), "Heroes tsy"),
view(Vector2f(400.0f, 300.0f), Vector2f(800.0f, 600.0f)),
level(0)
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
	decisionInfo = "0/476;186";
	positionX = "";
	positionY = "";
	idexOfCharacter = "";
}

Game::~Game()
{
	delete level;
}

void Game::play()
{
	cout << "Player" << playerTurn + 1 << " turn\n\n";

	while (window.isOpen())
	{
		eventHandler.readEvents(window);

		float time = clock.restart().asSeconds();
		globalTime = globalTime + time;
		Update(time);
		window.clear();
		if (level != nullptr)
		{
			level->Render(&window);
		}
		hud.display(view, window);
		window.display();
		int selectedFieldIndex = 0;
		//bot to 2 gracz
		if (playerTurn == 0){



			if (eventHandler.unitSelected && !flag)
			{
				selectedUnitIndex = selectedUnit(eventHandler.mousePosition); //index postaci na podstawie klikniecia myszki

				if (selectedUnitIndex != -1) //jesli index spoko
				{
					//wyswietl co wybrane i przemien flage
					cout << "Selected  " << level->players[playerTurn]->units[selectedUnitIndex]->getType() << endl;
					flag = true;
				}
				else
				{
					cout << "Wrong select! Try again" << endl;
					eventHandler.unitSelected = false;
					eventHandler.fieldSelected = false;
					eventHandler.numberOfClicks = 0;
				}
				//rysowanie zasiegu pionka
				if (selectedUnitIndex != -1)
				{
					DrawRange(level->players[playerTurn]->units[selectedUnitIndex]);
				}
			}
			//jesli wybrane pole i pionek
			if (eventHandler.fieldSelected && eventHandler.unitSelected)
			{
				//
				selectedFieldPos = selectedField(eventHandler.mousePosition, selectedFieldIndex);

				if (selectedFieldPos != Vector2f(0, 0)) //jesli wybrane pole na ktore ma isc  nie jest w 0,0
				{
					//ustawiamy nowa pozycje postaci
					level->players[playerTurn]->units[selectedUnitIndex]->field = level->fields[selectedFieldIndex];
					cout << "Selected field x: " << selectedFieldPos.x << ", y:" << selectedFieldPos.y << endl;
				}
				else
				{
					cout << "Wrong select! Try again" << endl;
					eventHandler.fieldSelected = false;
					eventHandler.numberOfClicks = 1;
				}
			}
			//jesli stanelismy i okazuje sie ze ktos jest w zasiegu to atakujemy
			if (selectedFieldPos != Vector2f(0, 0) && selectedUnitIndex != -1 && eventHandler.fieldSelected && eventHandler.unitSelected)
			{
				for (int i = 0; i < level->players[!playerTurn]->units.size(); i++)
				{
					if (level->players[!playerTurn]->units[i]->getRenderer()->GetBounds().intersects(level->fields[selectedFieldIndex]->getRenderer()->GetBounds()))
					{
						level->players[playerTurn]->units[selectedUnitIndex]->attack(level->players[!playerTurn]->units[i]);
					}
				}

				if (playerTurn == 1)
				{
					selectedFieldPos.x = selectedFieldPos.x + 55.0f;
				}
				//ustawia sprite'a wybranej jednsotki na wybranym polu
				level->players[playerTurn]->decide(level->players[!playerTurn], level->players[playerTurn]->units[selectedUnitIndex], selectedFieldPos);

				for each (Entity *field in level->fields)
				{
					field->render = false;
				}

				eventHandler.fieldSelected = false;
				eventHandler.unitSelected = false;
				flag = false;
				playerTurn = !playerTurn;
				cout << "Player" << playerTurn + 1 << " Turn\n\n";  //teraz czas na 2 gracza

			}
		}
		//gracz bot
		else
		{

			GetDecisionInfo(decisionInfo, positionX, positionY, idexOfCharacter);
			selectedUnitIndex = atoi(idexOfCharacter.c_str()); //index postaci na podstawie klikniecia myszki

			if (selectedUnitIndex != -1) //jesli index spoko
			{
				//wyswietl co wybrane i przemien flage
				cout << "Selected  " << level->players[playerTurn]->units[selectedUnitIndex]->getType() << endl;
				flag = true;
			}
			else
			{
				cout << "Wrong select! Try again" << endl;
				eventHandler.unitSelected = false;
				eventHandler.fieldSelected = false;
				eventHandler.numberOfClicks = 0;
			}
			//rysowanie zasiegu pionka
			if (selectedUnitIndex != -1)
			{
				DrawRange(level->players[playerTurn]->units[selectedUnitIndex]);
			}
			selectedFieldPos = selectedField(Vector2f(atoi(positionX.c_str()), atoi(positionY.c_str())), selectedFieldIndex);

			if (selectedFieldPos != Vector2f(0, 0)) //jesli wybrane pole na ktore ma isc  nie jest w 0,0
			{
				//ustawiamy nowa pozycje postaci
				level->players[playerTurn]->units[selectedUnitIndex]->field = level->fields[selectedFieldIndex];
				//cout << "Selected field x: " << selectedFieldPos.x << ", y:" << selectedFieldPos.y << endl;
			}
			else
			{
				cout << "Wrong select! Try again" << endl;
				eventHandler.fieldSelected = false;
				eventHandler.numberOfClicks = 1;
			}
			//jesli stanelismy i okazuje sie ze ktos jest w zasiegu to atakujemy
			if (selectedFieldPos != Vector2f(0, 0) && selectedUnitIndex != -1)
			{
				for (int i = 0; i < level->players[!playerTurn]->units.size(); i++)
				{
					if (level->players[!playerTurn]->units[i]->getRenderer()->GetBounds().intersects(level->fields[selectedFieldIndex]->getRenderer()->GetBounds()))
					{
						level->players[playerTurn]->units[selectedUnitIndex]->attack(level->players[!playerTurn]->units[i]);
					}
				}

				if (playerTurn == 1)
				{
					selectedFieldPos.x = selectedFieldPos.x + 55.0f;
				}
				//ustawia sprite'a wybranej jednsotki na wybranym polu
				level->players[playerTurn]->decide(level->players[!playerTurn], level->players[playerTurn]->units[selectedUnitIndex], selectedFieldPos);

				for each (Entity *field in level->fields)
				{
					field->render = false;
				}

				eventHandler.fieldSelected = false;
				eventHandler.unitSelected = false;
				flag = false;
				playerTurn = !playerTurn;
				cout << "Player" << playerTurn + 1 << " Turn\n\n";  //teraz czas na 2 gracza

			}

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
	FloatRect cursorRect(mousePosition.x, mousePosition.y, cursorPrecision, cursorPrecision);

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
		if (level->fields[i]->getRenderer()->GetBounds().contains(mousePosition) && level->fields[i]->render)
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
			level->fields[i]->render = true;
		}
	}
}

void Game::GetDecisionInfo(string decision, string& x, string& y, string& idexOfCharacter)
{
	size_t positionOfSlash = decision.find("/");
	idexOfCharacter = decision.substr(0, positionOfSlash);
	string positionXY = decision.substr(positionOfSlash + 1);
	size_t positionOfSemicolon = positionXY.find(";");
	y = positionXY.substr(positionOfSemicolon + 1);
	x = positionXY.substr(0, positionOfSemicolon);
}