#pragma once

#include <SFML/Graphics.hpp>

#include "EventHandler.h"
#include "Level.h"
#include "Hud.h"
#include "Tile.h"
#include "SpriteRenderer.h"
#include "Background.h"

using namespace sf;
class Level;
class Game
{
public:
	Game();
	virtual ~Game();
	bool OpponentUnit(Unit* unit);
	void play();
	void Update(float &time);
	EventHandler eventHandler;
	int selectedFieldIndex;
	int previousUnitIndex;
	int selectedUnit(Vector2f mousePosition);
	Vector2f selectedField(Vector2f mousePosition, int &index);
	void DrawRange(Unit *unit);
	bool playerTurn;
	Hud* hud;
	int selectedUnitIndex;
	void GetDecisionInfo(string decision, string& x, string& y, string& idexOfCharacter);
private:
	Level* level;
	Background *background;
	RenderWindow window;
	View view;
	Clock clock;
	float globalTime;
	Vector2f selectedFieldPos;
	bool flag;
	//do odczytywania wiadomosci z clipsa
	string decisionInfo;
	string idexOfCharacter;
	string positionY;
	string positionX;
};