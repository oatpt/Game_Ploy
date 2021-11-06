#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
	sumTimeErase = 0.0f;
}

Platform::~Platform()
{
}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);

}

void Platform::update(float deltaTime)
{
	body.move(sf::Vector2f(0.0f, 200.0f*deltaTime));
	
}
