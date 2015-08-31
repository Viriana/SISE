#include "Field.h"

Field::Field()
{
	type = "Field";
	hasUnit = false;
	inRange = false;
	index = -1;
	unit = nullptr;
	ColumnIndex = -1;
	RowIndex = -1;

	img = new Image();
	img->loadFromFile("Data\\graphics\\field.png");
	img->createMaskFromColor(Color(0, 255, 255, 255));
	texture = new Texture();
	texture->loadFromImage(*img);
	Renderer.SetTexture(*texture);
	Renderer.Sprite.setTextureRect(IntRect(0, 0, 43, 50)); // left, top, width, height
	Renderer.Sprite.setScale(1, 1);
}

Field::Field(const Field& obj)
{
	type = obj.type;
	hasUnit = obj.hasUnit;
	img = obj.img;
	texture = obj.texture;
	Renderer = obj.Renderer;
	index = obj.index;
	unit = obj.unit;
	ColumnIndex = obj.ColumnIndex;
	RowIndex = obj.RowIndex;
}

Field::~Field()
{
	delete texture;
	delete unit;
}
void Field::move()
{
}

void Field::Update()
{
}