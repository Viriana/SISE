#include "Player.h"


Player::Player(string name, float spriteRotation)
{
	this->name = name;

	units.push_back(new Knight());
	units.push_back(new Sorcerer());
	units.push_back(new Healer());
	units.push_back(new Archer());

	for (int i = 0; i < units.size(); i++)
	{
		units[i]->Renderer.SetScale(spriteRotation, 1.0f);

		if (spriteRotation == -1)
		{
			units[i]->setPosition(Vector2f(units[i]->GetPosition().x + 700.0f, units[i]->GetPosition().y));
		}
	}

}


Player::~Player()
{
}

Unit* Player::getPlayerUnits(int i)
{
	return units[i];
}

void Player::setPlayerUnits()
{

}

void Player::decide(Player *opponent)
{
	//wybieranie jednostki
	int decision;
	cout << name + " wybierz swoja jednostke ";
	cin >> decision;
	if (units[decision]->getIsAlive() == true)
	{
		units[decision]->setIsSelected(true);
		if (decision == 0)
			cout << "Wybrales rycerza " << units[decision]->getIsSelected() << endl;
		else if (decision == 1)
			cout << "Wybrales maga " << +units[decision]->getIsSelected() << endl;
		else if (decision == 2)
			cout << "Wybrales uzdrowiciela " << +units[decision]->getIsSelected() << endl;
		else if (decision == 3)
			cout << "Wybrales lucznika " << +units[decision]->getIsSelected() << endl;
		//wybieranie atakowanego wroga
		cout << name + " wybierz wroga jednostke ";
		cin >> decision;
		for (int i = 0; i < 4; ++i)
		{
			if (units[i]->getIsSelected() == true)
			{
				if (opponent->units[decision]->getIsAlive() == true)
				{
					units[i]->attack(opponent->units[decision]);
				}

				else
				{
					cout << "Ta jednostka jest martwa." << endl;
				}
			}
		}
	}


	else
	{
		cout << "Nie mozesz wybrac tej jednostki poniewaz jest martwa. Tracisz ture." << endl;
	}

	for (int i = 0; i < 4; ++i)
	{
		units[i]->setIsSelected(false);
	}
}