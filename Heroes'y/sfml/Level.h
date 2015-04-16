#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Background.h"
#include "Knight.h"
#include "Sorcerer.h"
#include "Field.h"

using namespace sf;
using namespace std;
class Game;
class Level

{
public:
	Level();
	virtual ~Level();
	int getLevelNumber();
	void Init();
	void Update( float dt );
	void Render(RenderWindow* window);
	Background* GetBackground();
	Game* Game;
private:
	
	int levelNumber;
	vector <Entity *> entities;
	vector <Entity *> pendingDestroy;
	Background* background;
	Knight* knight;
	Sorcerer* sorcerer;
	Field* field;
	
};
