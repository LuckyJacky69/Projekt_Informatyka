#include "Menu.h"
#include "Game.h"

Menu::Menu(float width, float height, double *converter)
{
	this->converter = converter;

	if(!font.loadFromFile("arial.ttf"))
		std::cout << "ERROR - file arial.ttf is missing." << "\n";

		menu[0].setFont(font);
		menu[0].setFillColor(sf::Color::White);
		menu[0].setString("Play");
		menu[0].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL + 1) * 1));

		menu[1].setFont(font);
		menu[1].setFillColor(sf::Color::White);
		if (diff_level == 0)
			menu[1].setString("Difficulty level: Easy");
		else if (diff_level == 1)
			menu[1].setString("Difficulty level: Medium");
		else if (diff_level == 2)
			menu[1].setString("Difficulty level: Hard");

		menu[1].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL + 1) * 2));

		menu[2].setFont(font);
		menu[2].setFillColor(sf::Color::White);
		menu[2].setString("Wczytaj poprzednia gre");
		menu[2].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL + 1) * 3));

		menu[3].setFont(font);
		menu[3].setFillColor(sf::Color::White);
		menu[3].setString("Best Scores");
		menu[3].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL + 1) * 4));

		menu[4].setFont(font);
		menu[4].setFillColor(sf::Color::White);
		menu[4].setString("Exit");
		menu[4].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL + 1) * 5));
}

void Menu::draw( sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_LEVEL; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex >= -1)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		if (selectedItemIndex == -1)
			selectedItemIndex = 4;
		menu[selectedItemIndex].setFillColor(sf::Color::Green);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 <= MAX_LEVEL)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		if (selectedItemIndex == 5)
			selectedItemIndex = 0;
		menu[selectedItemIndex].setFillColor(sf::Color::Green);
	}
}
int Menu::getPressedItem()
{
	return selectedItemIndex;
}

void Menu::change_diff()
{
	diff_level++;
	if (diff_level > 2)
		diff_level = 0;	
	std::cout << "\n"<<diff_level;
	if (diff_level == 0)
	{
		menu[1].setString("Difficulty level: Easy");
		*converter = 0.7;
	}
	else if (diff_level == 1)
	{
		menu[1].setString("Difficulty level: Medium");
		*converter = 1;
	}
	else if (diff_level == 2)
	{
		menu[1].setString("Difficulty level: Hard");
		*converter = 3;
	}
}

void Menu::initDelay(int my_delay)
{
	sf::Clock zegar;
	sf::Time czas;
	while (1)
	{
		czas = zegar.getElapsedTime();
		if (czas.asMilliseconds() > my_delay)
		{
			zegar.restart();
			break;
		}
	}
}