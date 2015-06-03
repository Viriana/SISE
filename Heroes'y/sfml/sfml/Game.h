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
	void play();
	void Update(float &time);
	EventHandler eventHandler;
	int selectedUnit(Vector2f mousePosition);
	Vector2f selectedField(Vector2f mousePosition, int &index);
	void DrawRange(Unit *unit);
	bool playerTurn;
private:
	Level* level;
	Background *background;
	RenderWindow window;
	View view;
	Hud* hud;
	Clock clock;
	float globalTime;
	int selectedUnitIndex;
	Vector2f selectedFieldPos;
	bool flag;
};