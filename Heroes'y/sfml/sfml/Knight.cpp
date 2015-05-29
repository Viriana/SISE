#include "Knight.h"

Knight::Knight()
{
	type = "Knight";
	maxHealthPoints = 7;
	currentHealthPoints = 7;
	armor = 5;
	strength = 5;
	range = 1;
	movementSpeed = 5;
	meleeAccuracy = 70;
	isAlive = true;
	isSelected = false;
	img = new Image();
	img->loadFromFile("Data\\graphics\\battle.png");
	img->createMaskFromColor(Color(0, 255, 255, 255));
	texture = new Texture;
	texture->loadFromImage(*img);
	Renderer.SetTexture(*texture);
	Renderer.Sprite.setTextureRect(IntRect(42, 729, 100, 120)); // left, top, width, height
	Renderer.Sprite.setScale(1, 1);
	Renderer.Sprite.setPosition(Vector2f(50, 100));
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

void Knight::attack(Unit *targetUnit)
{
	int accuracyTest = rand() % 100 + 1;
	int damage = strength;
	if (accuracyTest <= meleeAccuracy)
	{
		damage += rand() % 3 + 1;
		cout << "sila ciosu: " << damage << endl;
		damage -= targetUnit->getArmor();
		cout << "Twoj cios trafil przeciwnika zadajac " << damage << " obrazen" << endl;
		if (targetUnit->getCurrentHealthPoints() > 0)
		{
			targetUnit->setCurrentHealthPoints(damage);
		}
		if (targetUnit->getCurrentHealthPoints() <= 0)
		{
			cout << "umarlem!" << endl;
			targetUnit->isAlive = false;
		}
	}
	else
		cout << "Chybiles" << endl;
}