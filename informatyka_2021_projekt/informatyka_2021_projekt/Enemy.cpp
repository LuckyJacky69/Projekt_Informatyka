#include "Enemy.h"
#include "Game.h"
void Enemy::initVariables()
{
	this->pointCount = rand() % 8+ 2;										//2 <x< 10
	this->type		 = 0;
	this->speed		 = pow(this->pointCount, -1)*(-4);						//-2<speed<-1 smaller one should be faster
	this->hpMax		 = this->pointCount;
	this->hp		 = this->hpMax;
	this->damage	 = this->pointCount*2;
	this->points	 = this->pointCount;
}
void Enemy::initTexture()
{
	this->randTexture = rand() % 3 + 1;	//	each object has randomised texture (5 different)

	if (randTexture==1 && !this->texture.loadFromFile("Textures/asteroid1.png"))
	{
		std::cout << "ERROR - file asteroid1.png is missing." << "\n";
	}
	if (randTexture == 2 && !this->texture.loadFromFile("Textures/asteroid2.jpg"))
	{
		std::cout << "ERROR - file asteroid2.jpg is missing." << "\n";
	}
	if (randTexture == 3 && !this->texture.loadFromFile("Textures/asteroid3.jpg"))
	{
		std::cout << "ERROR - file asteroid3.jpg is missing." << "\n";
	}
	if (randTexture == 4 && !this->texture.loadFromFile("Textures/asteroid4.jpg"))
	{
		std::cout << "ERROR - file asteroid4.jpg is missing." << "\n";
	}
	if (randTexture == 5 && !this->texture.loadFromFile("Textures/asteroid5.jpg"))
	{
		std::cout << "ERROR - file asteroid5.jpg is missing." << "\n";
	}
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initShape();
	this->shape.setPosition(pos_x, pos_y);
}
void Enemy::initShape()
{
	this->shape.setRadius(this->pointCount*5);	//radius (bigger ones will give more points)
	this->shape.setPointCount(rand() % 12 + 3); //edges
	this->shape.setTexture(&texture);
}

Enemy::~Enemy()
{

}

const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();		//it has to be copy, no reference
}

//functions
const int & Enemy::getPoints() const
{
	return this->points;
}
const int& Enemy::getDamage() const
{
	return this->damage;
}

void Enemy::update()
{
	this->shape.move(this->speed, 0.f);				//enemies moving to the left side + their speed
}
void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
