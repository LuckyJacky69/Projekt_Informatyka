#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	//attributes
	int hp=100;
	int hpMax;
	int damage;
	float movementSpeed;
	float attackCooldown;
	float attackCooldownMax;

	//functions priv
	void initVariables();
	void initTexture();
	void initSprite();
	void initGui();

public:
	Player(float hp);
	virtual ~Player();
	//Accessor
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getDamage() const;
	const int& getHpMax() const;
	//Modifiers

	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);
	//functions

	void move(const float dirX, const float dirY);
	const bool canAttack();
	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);

};

