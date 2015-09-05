#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class SpriteRenderer
{
public:
	SpriteRenderer();
	virtual ~SpriteRenderer();
	void Render(RenderWindow* window, int animation);
	Sprite Sprite;
	void SetTexture(Texture& texture);
	void Move(Vector2f v);
	FloatRect GetBounds();
	Vector2f GetPosition();
	void SetScale(float a, float b);
private:
	int LastAnimationIndex;
	int LastAnimationFrameIndex;
	
};