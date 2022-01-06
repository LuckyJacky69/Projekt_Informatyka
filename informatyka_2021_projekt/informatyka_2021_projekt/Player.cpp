#include "Player.h"
#include <iostream>

void Player::initTexture()
{
	//loading texture from file
	if (!this->texture.loadFromFile("Textures/ship.png"))
	{
		std::cout << "ERROR - file ship.png is missing."<<"\n";
	}
}

void Player::initSprite()
{
	//setting texture to the sprite
	this->sprite.setTexture(this->texture);

	//Resizing sprite
	this->sprite.scale(1.5f, 1.5f);
}


Player::Player()
{
	this->movementSpeed = 2.f;
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}
//direction control
void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed*dirX, this->movementSpeed*dirY);
}
//func
void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

