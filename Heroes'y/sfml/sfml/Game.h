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
private:
	Level* level;
	Background *background;
	RenderWindow window;
	View view;
	Player *player1;
	Player *player2;
	Hud hud;
	Clock clock;
	float globalTime;
};