#include "Sorcerer.h"


Sorcerer::Sorcerer()
{
	type = "Sorcerer";
	maxHealthPoints = 7;
	currentHealthPoints = 7;
	armor = 1;
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
	Renderer.Sprite.setTextureRect(IntRect(42, 905, 100, 120)); // left, top, width, height
	Renderer.Sprite.setScale(1, 1);
}


Sorcerer::~Sorcerer()
{
	delete img;
	delete texture;
}
void Sorcerer::Update()
{
}

void Sorcerer::attack()
{

}
