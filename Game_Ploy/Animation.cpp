#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{

}

void Animation::Update(int col,int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime; 

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
	}
	
	if (currentImage.x >= col)
	{
		currentImage.x = 0;
	}

	uvRect.top = currentImage.y * uvRect.height;
	uvRect.left = currentImage.x * uvRect.width;

}
