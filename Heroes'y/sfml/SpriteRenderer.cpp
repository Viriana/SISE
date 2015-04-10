#include "SpriteRenderer.h"
#include <stdio.h>

SpriteRenderer::SpriteRenderer()
{
}
SpriteRenderer::~SpriteRenderer()	
{
}

void SpriteRenderer::Render(sf::RenderWindow* window, int animation)
{
	window-> draw( Sprite );
}
void SpriteRenderer::SetTexture(sf::Texture& texture)
{
	Sprite.setTexture(texture, true);
}

void SpriteRenderer::Move(Vector2f v)
{
	Sprite.move( v );
}
FloatRect SpriteRenderer::GetBounds()
{
	return Sprite.getGlobalBounds();
}
Vector2f SpriteRenderer::GetPosition()
{
	return Sprite.getPosition();
}