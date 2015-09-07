#pragma once

#include <SFML/Graphics.hpp>

#include "EventHandler.h"
#include "Level.h"
#include "Hud.h"
#include "Tile.h"
#include "SpriteRenderer.h"
#include "Background.h"
#include "Router.h"
#include <vector>
#include <windows.h>
#include "fl\Headers.h"

using namespace sf;
using namespace fl;
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
	string ProcessFuzzyDecision(Player* player1, Player* player2);
private:
	bool isFuzzy;
	Level* level;
	Background *background;
    fl::Engine* fuzzyEngine; //potrzebne dla przetwarzania info z fuzzy 
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