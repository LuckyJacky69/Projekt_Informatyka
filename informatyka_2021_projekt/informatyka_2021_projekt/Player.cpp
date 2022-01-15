#include "Player.h"
#include "Menu.h"
#include <iostream>

//ms inicjation
void Player::initVariables()
{
	this->movementSpeed = 2;
	this->attackCooldownMax = 20.f;
	this->attackCooldown = this->attackCooldownMax;
	this->hpMax = 100;
	this->hp = this->hpMax;
}

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
	this->initVariables(); 
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}
//creating projectile position same as player's.
const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}


const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

// is that important?
void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}
void Player::setHp(const int hp)
{
	this->hp = hp;
}
void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp <= 0)
		this->hp = 0;
}
//direction control
void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed*dirX, this->movementSpeed*dirY);
}
//func

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	else return false;	
}

void Player::updateAttack()
{
	if(this->attackCooldown<this->attackCooldownMax)
		this->attackCooldown += 0.5f;
}

void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

