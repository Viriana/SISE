#pragma once

#include "Unit.h"

using namespace std;
using namespace sf;

class Knight : public Unit
{
public:
	Knight();
	virtual ~Knight();
	void move();
	virtual void Update() override;
	void attack();
private:
	Image *img;
	Texture *texture;
	Vector2f *position = new Vector2f(50, 150);
};
