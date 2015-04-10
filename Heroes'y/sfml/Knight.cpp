#include "Knight.h"

Knight::Knight()
{
	type = "Knight";

	img = new Image();
	img->loadFromFile("Data\\graphics\\battle.png");
	img->createMaskFromColor(Color(0, 255, 255, 255));
	texture = new Texture;
	texture->loadFromImage(*img);
	Renderer.SetTexture(*texture);
	Renderer.Sprite.setTextureRect(IntRect(42, 33, 100, 120)); // left, top, width, height
	Renderer.Sprite.setScale(1, 1);
}
Knight::~Knight()
{
	delete img;
	delete texture;
}
void Knight::move()
{
}

void Knight::Update()
{
}