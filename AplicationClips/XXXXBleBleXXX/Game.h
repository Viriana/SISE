#pragma once

#include <SFML/Graphics.hpp>

#include "EventHandler.h"
#include "Level.h"
#include "Hud.h"
#include "Tile.h"
#include "SpriteRenderer.h"
#include "Background.h"
#include "Router.h"

#include <windows.h>

using namespace sf;
class Level;
class Game
{
public:
	Game();
	virtual ~Game();
	bool OpponentUnit(Unit* unit);
	void play(myCLIPSRouter &theRouter, CLIPSCPPEnv &theEnv);
	void Update(float &time);
	EventHandler eventHandler;
	int selectedFieldIndex;
	int previousUnitIndex;
	int selectedUnit(Vector2f mousePosition);
	Vector2f selectedField(Vector2f mousePosition, int &index);
	Vector2f selectedField(int index);
	void DrawRange(Unit *unit);
	bool playerTurn;
	Hud* hud;
	int selectedUnitIndex;
	void GetDecisionInfo(string decision, string& indexOfSelectedField, string& indexOfCharacter);
	void setDecisionInfo(string newDecision);
	void UpdateClipsFacts(myCLIPSRouter &theRouter, CLIPSCPPEnv &theEnv);
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
	string selectedUnitIndexStr;
	string selectedFieldIndexStr;
};