#include "Field.h"

Field::Field()
{
	type = "Field";
	hasUnit = false;
	inRange = false;

	img = new Image();
	img->loadFromFile("Data\\graphics\\field.png");
	img->createMaskFromColor(Color(0, 255, 255, 255));
	texture = new Texture;
	texture->loadFromImage(*img);
	Renderer.SetTexture(*texture);
	Renderer.Sprite.setTextureRect(IntRect(0, 0, 43, 50)); // left, top, width, height
	Renderer.Sprite.setScale(1, 1);
}
Field::~Field()
{
	delete img;
	delete texture;
}
void Field::move()
{
}

void Field::Update()
{
}