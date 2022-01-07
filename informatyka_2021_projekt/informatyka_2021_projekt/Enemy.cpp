#include "Enemy.h"

void Enemy::initTexture()
{
	if (!this->texture.loadFromFile("Textures/asteroid.png"))
	{
		std::cout << "ERROR - file asteroid.png is missing." << "\n";
	}
}

void Enemy::initShape()
{
	this->shape.setRadius(rand()%10+30);	//radius
	this->shape.setPointCount(rand()%12+3 ); //edges
	this->shape.setTexture(&texture);
}

void Enemy::initVariables()
{
	this->type	 =	 0;
	this->speed =	-2.f;
	this->hp	 =	10;
	this->hpMax	 =	 0;
	this->damage =	 1;
	this->points =	 5;

}
Enemy::Enemy(float pos_x, float pos_y)
{
	this->initTexture();
	this->initShape();
	this->initVariables();
	this->shape.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{

}

const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();		//it has to be copy, no reference
}

//functions
void Enemy::update()
{
	this->shape.move(this->speed, 0.f);				//enemies moving to the left side + their speed
}
void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
