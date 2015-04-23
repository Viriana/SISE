#include "Level.h"
#include "Game.h"

Game::Game():
window(VideoMode(800, 600, 32), "Heroes tsy"),
view(Vector2f(400.0f, 300.0f), Vector2f(800.0f, 600.0f)),
level(0)
{
	window.setFramerateLimit(30);
	window.setView(view);
	window.setKeyRepeatEnabled(false);

	globalTime = 0.0f;
	level = new Level();
	level->Game = this;
	level->Init();
}

Game::~Game()
{
	delete level;
}

void Game::play()
{
	while (window.isOpen())
	{
		eventHandler.readEvents(window);
		
		float time = clock.restart().asSeconds();
		globalTime = globalTime + time;
		Update(time);
		window.clear();
		if (level != nullptr)
		{
			level-> Render( &window );
		}
		
		hud.display(view, window);
		window.display();
	}
}

void Game::Update(float &time)
{
	if (level != nullptr)
	{
		level->Update(time);
	}
}