#include "Hud.h"

Hud::Hud()
{
	hudFont.loadFromFile("Data/fonts/emulogic.ttf");
}

Hud::~Hud()
{
}

void Hud::display(View &view, RenderWindow &window)
{
	Text text("Heroes tsy", hudFont);

	text.setPosition(view.getCenter().x - 290, view.getCenter().y - 300);
	text.setCharacterSize(15);
	text.setColor(Color::White);

	window.draw(text);
}