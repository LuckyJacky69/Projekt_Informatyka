#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
class Shot
{
private:
	sf::Sprite shape;
	sf::Vector2f direction;
	float movementSpeed;
public:
	Shot();
	Shot(sf::Texture* texture,float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
	virtual ~Shot();

	//Accessor
	const sf::FloatRect getBounds() const;
	void update();
	void render(sf::RenderTarget* target);
};

