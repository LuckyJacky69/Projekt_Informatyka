#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	//attributes
	float movementSpeed;

	//func
	void initTexture();
	void initSprite();
public:
	Player();
	virtual ~Player();

	//func
	void move(const float dirX, const float dirY);
	void update();
	void render(sf::RenderTarget& target);

};

