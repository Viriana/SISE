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
	Hud();
	virtual ~Hud();
	void display(View &view, RenderWindow &window);
private:
	Font hudFont;
};