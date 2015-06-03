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
	isAlive = true;
	isSelected = false;
	inteligence = 70;

	img = new Image();
	img->loadFromFile("Data\\graphics\\battle.png");
	img->createMaskFromColor(Color(0, 255, 255, 255));
	texture = new Texture;
	texture->loadFromImage(*img);
	Renderer.SetTexture(*texture);
	Renderer.Sprite.setTextureRect(IntRect(42, 2658, 100, 120)); // left, top, width, height
	Renderer.Sprite.setScale(1, 1);
	Renderer.Sprite.setPosition(Vector2f(75, 440));
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

void Healer::heal(Unit* targetUnit)
{
	int inteligenceTest = rand() % 100 + 1;
	int damage = strength;
	if (inteligenceTest <= inteligence)
	{
		damage += rand() % 3 + 1;
		//cout << "moc uzdrowienia: " << damage << endl;
		message = "moc uzdrowienia: " + to_string(damage) + "\n";
		damage -= targetUnit->getArmor();
		//cout << "Odnowi³es sojusznikowi " << damage << " obrazen" << endl;
		message = message + "Odnowiles jednostce " + targetUnit->getType() + " " + to_string(damage) + " obrazen" + "\n";
		if (targetUnit->getCurrentHealthPoints() > 0)
		{
			targetUnit->setCurrentHealthPoints(damage);
		}
		/*if (targetUnit->getCurrentHealthPoints() <= 0)
		{
			cout << "umarlem!" << endl;
			targetUnit->isAlive = false;
		}*/
	}
	/*else
		cout << "Chybiles" << endl;*/
}

//void Healer::attack(Unit* targetUnit)
//{
//
//}
