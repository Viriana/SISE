#include "Healer.h"


Healer::Healer()
{
	type = "Healer";
	maxHealthPoints = 7;
	currentHealthPoints = 7;
	armor = 5;
	strength = 4;
	range = 4;
	movementSpeed = 2;
	setStartPosition(*position);
	img = new Image();
	img->loadFromFile("Data\\graphics\\battle.png");
	img->createMaskFromColor(Color(0, 255, 255, 255));
	texture = new Texture;
	texture->loadFromImage(*img);
	Renderer.SetTexture(*texture);
	Renderer.Sprite.setTextureRect(IntRect(42, 2658, 100, 200)); // left, top, width, height
	Renderer.Sprite.setScale(1, 1);
}


Healer::~Healer()
{
	delete img;
	delete texture;
}

void Healer::move()
{
}

void Healer::Update()
{
}

void Healer::heal()
{
}
