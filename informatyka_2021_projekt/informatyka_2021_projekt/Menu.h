#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define MAX_LEVEL 5

class Menu
{
public:
	Menu(float width, float height);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getPressedItem();	
	float diff_level = 1;
	float converter = 1;
	void change_diff();
	void initDelay(int my_delay);	
	void getConverter(float x) ;

private:
	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text menu[MAX_LEVEL];
};



/*




*/
