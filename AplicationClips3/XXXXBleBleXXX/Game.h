#pragma once

#include <SFML/Graphics.hpp>

#include "EventHandler.h"
#include "Level.h"
#include "Hud.h"
#include "Tile.h"
#include "SpriteRenderer.h"
#include "Background.h"
#include "Router.h"
#include "fl\Headers.h"

#include <windows.h>

using namespace sf;
class Level;
class Game
{
public:
	Game();
	virtual ~Game();
	bool OpponentUnit(Unit* unit);
	vector<int> ComputeAvailableFields();
	int ComputeDistanceHexGrid(Vector2f A, Vector2f B);
	void UpdateAvailableFieldsInCLips(vector<int> tab, CLIPSCPPEnv& theEnv);
	void UpdateUnitsInClips(CLIPSCPPEnv& theEnv);
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
	void setDecisionInfo(string newDecision);
	void ComputeUnitSelectionInCLips(CLIPSCPPEnv& theEnv);
	void ComputeFieldSelectionInClips(CLIPSCPPEnv& theEnv);
	string GetSelectedUnitFromClips(myCLIPSRouter& theRouter, CLIPSCPPEnv& theEnv);
	string GetSelectedFieldFromClips(myCLIPSRouter& theRouter, CLIPSCPPEnv& theEnv);
	void GenerateRandomNumberForClipse(int from, int to, CLIPSCPPEnv &theEnv);
	string ProcessFuzzyDecision(Player* player1, Player* player2);
	void GetDecisionInfo(string decision, string& indexOfSelectedField, string& indexOfCharacter);
	vector<int> ComputeAvailableFields(int &UnitIndex);
	bool isFuzzy;
private:
	fl::Engine* fuzzyEngine; //potrzebne dla przetwarzania info z fuzzy 
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