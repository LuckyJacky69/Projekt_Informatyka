#include "Shot.h"

Shot::Shot()
{
	
}

Shot::Shot(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = 1.15*movement_speed; //projectile speed should be faster than ship's speed
}

Shot::~Shot()
{

}

const sf::FloatRect Shot::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Shot::update()
{
	//updating movement of a projectile
	this->shape.move(this->movementSpeed * this->direction);
}

void Shot::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}