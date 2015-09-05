#include "Background.h"

Background::Background()
{
	texture = new Texture;
	texture->loadFromFile("Data\\graphics\\background1.png");
	Renderer.SetTexture(*texture);
	Renderer.Sprite.setScale(1.0f, 1.0f);
	isAlive = true;
}


Background::~Background()
{
	delete texture;
}