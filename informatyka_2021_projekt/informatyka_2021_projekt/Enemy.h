#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
class Enemy
{
private:
	
	sf::CircleShape shape;
	sf::Texture texture;
	int randTexture;
	void initTexture();
	void initShape();

public:
	float pointCount;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;
	double converter=1;
	Enemy(float pos_x, float pos_y, double converter);
	virtual ~Enemy();

	//Accessors
	void initVariables();
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;					//getting points
	const int& getDamage() const;
	const int& getHp() const;

	void setHp(const int hp);
	void loseHp(const int value);
	//Functions
	void update();
	void render(sf::RenderTarget* target);
};


