#include "Player.h"


Player::Player(Knight* knight, Sorcerer* sorcerer, string name)
{
	units[0] = knight;
	units[1] = sorcerer;
	this->name = name;
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
		//wybieranie atakowanego wroga
		cout << name + " wybierz wroga jednostke ";
		cin >> decision;
		for (int i = 0; i < 2; ++i)
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

	for (int i = 0; i < 2; ++i)
	{
		units[i]->setIsSelected(false);
	}
}