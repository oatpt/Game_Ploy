#pragma once
#include <SFML\Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture* texture,sf::Vector2u imafeCount,float switchTime);
	~Animation();


	void Update(int col,int row, float deltaTime);

public:
	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

