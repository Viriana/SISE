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
#include <map>

#include <windows.h>

using namespace sf;
using namespace fl;

typedef map<int, Unit*> sortedList;
typedef pair<int, Unit*> indexPair;
typedef vector<int>::iterator it;

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
	void setDecisionInfo(string& newDecision);
	void ComputeUnitSelectionInCLips(CLIPSCPPEnv& theEnv);
	void ComputeFieldSelectionInClips(CLIPSCPPEnv& theEnv);
	string GetSelectedUnitFromClips(myCLIPSRouter& theRouter, CLIPSCPPEnv& theEnv);
	string GetSelectedFieldFromClips(myCLIPSRouter& theRouter, CLIPSCPPEnv& theEnv);
	void GenerateRandomNumberForClipse(int from, int to, CLIPSCPPEnv &theEnv);
	void ProcessFuzzyDecision(Player* player1, Player* player2);
	void GetDecisionInfo(string decision, string& indexOfSelectedField, string& indexOfCharacter);
	vector<int> ComputeAvailableFields(int &UnitIndex);
	int FindClosestEnemysDistanceToPlayer(vector<Unit*> &enemies, Unit* selectedCharacter);
	vector<int> CalculateAviableDistances(int characterIndex, vector<int> aviableFileds);
	Unit* Game::FindClosestEnemy(vector<Unit*> &enemies, Unit* selectedCharacter);
	int RunAwayFromEnemy(Unit* enemy, Unit* character, vector<int> aviableFields, int currentDistance, int currentCharacterIndex);
	bool isFuzzy;
	sortedList  enemiesDictionary;
	string FuzzyDecision;
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
	string selectedUnitIndexStr;
	string selectedFieldIndexStr;
};