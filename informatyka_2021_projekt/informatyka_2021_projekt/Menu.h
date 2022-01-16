#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define MAX_LEVEL 5

class Menu
{
public:
	Menu(float width, float height, double *converter);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getPressedItem();	
	float diff_level = 1;
	double *converter;
	void change_diff();

	//Accessors
	void initDelay(int my_delay);

private:
	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text menu[MAX_LEVEL];
};

