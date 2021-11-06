#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
class Platform
{
public:
	Platform(sf::Texture* texture,sf::Vector2f size,sf::Vector2f position);
	~Platform();

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }
	sf::RectangleShape body;

	void update(float deltaTime);

	float sumTimeErase;
	void sumTime(float deltaTime){
		sumTimeErase += deltaTime;
	}
private:
	
};


