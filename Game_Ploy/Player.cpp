#include "Player.h"
#include<stdio.h>
static const float VIEW_WIDTH = 1920.0f;

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHight):
	animation(texture,imageCount,switchTime)
{
	this->speed = speed;
	this->jumpHight = jumpHight;
	row = 0;

	body.setSize(sf::Vector2f(162.0f, 202.5f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(400.0f, 800.0f);
	body.setTexture(texture);
}
Player::~Player()
{

}


void Player::Update(float deltaTime)
{
	velocity.x = 0.0f;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&body.getPosition().x>body.getOrigin().x)
		velocity.x -= speed ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && body.getPosition().x < VIEW_WIDTH-body.getOrigin().x)
		velocity.x += speed ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHight);
	}

	velocity.y += 981.0f * deltaTime;
	if (velocity.x > 0)
		row = 0,col = 20;

	else if (velocity.x < 0)
		row = 1, col = 20;

	else row = 2, col = 16;
	animation.Update(col,row, deltaTime);
	body.setTextureRect(animation.uvRect);
	body.move(velocity*deltaTime);
	//printf("%f\n", velocity.y);


}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollosion(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f;
	}

	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
	}

	if (direction.y < 0.0f)
	{
		velocity.y = 0.0f;
		canJump = true;
	}

	else if (direction.y > 0.0f)
	{
		velocity.y = 0.0f;
	}
}
