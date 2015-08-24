#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>

#include <SFML/Graphics.hpp>

#include "Level.h"
#include "Entity.h"

using namespace sf;
using namespace std;

class Hud : public Entity
{
public:
	Hud(View &view, RenderWindow &window);
	virtual ~Hud();
	void display(int PlayerTurn);
	void WriteLine(string text);
	void WriteGameState(string text);
private:
	Font hudFont;
	View *view;
	RenderWindow *window;
	Text text1;
	Text text2;
};