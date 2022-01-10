#pragma once
#include "Game.h"

#define MAX_LEVEL 5
class Menu
{
public:
	Menu(float width, float height);
	sf::RenderWindow* window;
	void draw(sf::RenderWindow& window);
	void diff_update(float width, float height);
	void MoveUp();
	void MoveDown();
	int getPressedItem();
	void initWindow();
	void render();
	void initDelay(int my_delay);
	void update();
	int selectedItemIndex = 0;
	int menu_selected_flag = 0;
private:
	sf::Sprite background;
	sf::Texture backgroundTexture;
	sf::Font font;
	sf::Text menu[MAX_LEVEL];



};

/*




*/
