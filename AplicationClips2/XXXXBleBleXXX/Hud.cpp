#include "Hud.h"

Hud::Hud(View &view, RenderWindow &window)
{
	hudFont.loadFromFile("Data/fonts/emulogic.ttf");
	this->view = &view;
	this->window = &window;
}

Hud::~Hud()
{
}

void Hud::display(int PlayerTurn)
{
	Text text("Heroes tsy", hudFont);

	text.setPosition(view->getCenter().x - 290, view->getCenter().y - 300);
	text.setCharacterSize(15);
	text.setColor(Color::White);

	window->draw(text);
	window->draw(text1);
	window->draw(text2);

	if (PlayerTurn == 0)
	{
		Text player1("Player1", hudFont);

		player1.setPosition(view->getCenter().x - 290, view->getCenter().y - 250);
		player1.setCharacterSize(15);
		player1.setColor(Color::White);
		window->draw(player1);
	}


	if (PlayerTurn == 1)
	{
		Text player2("Player2", hudFont);

		player2.setPosition(view->getCenter().x + 150, view->getCenter().y - 250);
		player2.setCharacterSize(15);
		player2.setColor(Color::White);

		window->draw(player2);
	}

}

void Hud::WriteLine(string text)
{
	Text temp(text, hudFont);
	text1 = temp;

	text1.setPosition(view->getCenter().x, view->getCenter().y + 270);
	text1.setCharacterSize(7);
	text1.setColor(Color::White);

	window->draw(text1);
}

void Hud::WriteGameState(string text)
{
	Text temp(text, hudFont);
	text2 = temp;

	text2.setPosition(0, view->getCenter().y + 280);
	text2.setCharacterSize(15);
	text2.setColor(Color::White);

	window->draw(text2);
}