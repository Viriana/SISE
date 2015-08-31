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
	dexterity = 70;
	isAlive = true;
	isSelected = false;
	img = new Image();
	img->loadFromFile("Data\\graphics\\battle.png");
	img->createMaskFromColor(Color(0, 255, 255, 255));
	texture = new Texture;
	texture->loadFromImage(*img);
	Renderer.SetTexture(*texture);
	Renderer.Sprite.setTextureRect(IntRect(42, 379, 100, 120)); // left, top, width, height
	Renderer.Sprite.setScale(1, 1);
	Renderer.Sprite.setPosition(Vector2f(50, 310));
}


Archer::~Archer()
{
	delete img;
	delete texture;
}
void Archer::Update()
{
}

void Archer::Heal()
{
	
}

void Archer::attack(Unit *targetUnit)
{
	int accuracyTest = rand() % 100 + 1;
	int damage = strength;
	if (accuracyTest <= dexterity)
	{
		damage += rand() % 3 + 1;
		//cout << "sila strzalu: " << damage << endl;
		message = "sila strzalu: " + to_string(damage) + "\n";
		damage -= targetUnit->getArmor();
		//cout << "Twoj cios trafil przeciwnika zadajac " << damage << " obrazen" << endl;
		message = message + "Twoja strzala ranila przeciwnika zadajac " + to_string(damage) + " obrazen" + "\n";
		if (targetUnit->getCurrentHealthPoints() > 0)
		{
			targetUnit->setCurrentHealthPoints(damage);
		}
		if (targetUnit->getCurrentHealthPoints() <= 0)
		{
			//cout << "przeciwnik zginal!" << endl;
			message = message + "przeciwnik zginal!" + "\n";
			targetUnit->isAlive = false;
		}
	}
	else
	{
		//cout << "Chybiles" << endl;
		message = message + "Chybiles" + "\n";
	}
}
