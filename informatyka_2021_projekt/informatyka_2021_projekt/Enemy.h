#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{
private:
	sf::CircleShape shape;
	sf::Texture texture;
	float pointCount;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	int randTexture;
	void initTexture();

	void initShape();
	void initVariables();

public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	//Accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;					//getting points
	const int& getDamage() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};

