#include "Archer.h"

Archer::Archer()
{
	type = "Archer";
	maxHealthPoints = 7;
	currentHealthPoints = 7;
	armor = 2;
	strength = 3;
	range = 4;
	movementSpeed = 2;

	setStartPosition(*position);
	img = new Image();
	img->loadFromFile("Data\\graphics\\battle.png");
	img->createMaskFromColor(Color(0, 255, 255, 255));
	texture = new Texture;
	texture->loadFromImage(*img);
	Renderer.SetTexture(*texture);
	Renderer.Sprite.setTextureRect(IntRect(42, 379, 100, 120)); // left, top, width, height
	Renderer.Sprite.setScale(1, 1);
}


Archer::~Archer()
{
	delete img;
	delete texture;
}
void Archer::Update()
{
}

void Archer::attack(Unit *targetUnit)
{
	int accuracyTest = rand() % 100 + 1;
	int damage = strength;
	if (accuracyTest <= dexterity)
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
			targetUnit->setIsAlive(false);
		}
	}
	else
		cout << "Chybiles" << endl;
}
