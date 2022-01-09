#include "Menu.h"

Menu::Menu(float width, float height)
{
	if(!font.loadFromFile("arial.ttf"))
		std::cout << "ERROR - file arial.ttf is missing." << "\n";

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL+1)*1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Difficulty Level");
	menu[1].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL + 1)*2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Help");
	menu[2].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL + 1)*3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Best Scores");
	menu[3].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL + 1)*4));

	menu[4].setFont(font);
	menu[4].setFillColor(sf::Color::White);
	menu[4].setString("Exit");
	menu[4].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL + 1)*5));
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
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Green);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_LEVEL)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Green);
	}
}
int Menu::getPressedItem()
{
	return selectedItemIndex;
}



void Menu::diff_update(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "ERROR - file arial.ttf is missing." << "\n";

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Easy");
	menu[0].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Medium");
	menu[1].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Hard");
	menu[2].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Back");
	menu[3].setPosition(sf::Vector2f(width / 4, height / (MAX_LEVEL + 1) * 4));
}

void Menu::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(640, 480), "Far from home", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
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

void Menu::update()
{

	
}

void Menu::render()
{
	this->initWindow();
	Menu menu(this->window->getSize().x, this->window->getSize().y);
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->window->close();

		if (menu_selected_flag == 0)
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					initDelay(250);
					menu.MoveUp();
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					initDelay(250);
					menu.MoveDown();
				}
				if (menu_selected_flag == 0)
				{
					if (event.key.code == sf::Keyboard::Enter && menu.getPressedItem() == 0)        //PLAY + ask do you want to leave?
					{
						menu_selected_flag = 1;
						Game game;
						game.run();
					}

					if (event.key.code == sf::Keyboard::Enter && menu.getPressedItem() == 1)        //Difficulty level inside
					{
						menu_selected_flag = 1;
						menu.getPressedItem() == 0;
					}

					if (event.key.code == sf::Keyboard::Enter && menu.getPressedItem() == 2)        //Help module
					{
						menu_selected_flag = 1;
						std::cout << "Help module soon..." << std::endl;
					}
					if (event.key.code == sf::Keyboard::Enter && menu.getPressedItem() == 3)        //Best scores (we can see 5 best scores)
					{
						menu_selected_flag = 1;
						std::cout << "Best scores soon..." << std::endl;
					}
					if (event.key.code == sf::Keyboard::Enter && menu.getPressedItem() == 4)        //Exit
					{
						std::cout << "Wyjscie z gry" << std::endl;
						this->window->close();
					}
				}
			}
		}
		if (menu_selected_flag == 1)																//return from game to menu after pressing Escape
		{
			if (event.key.code == sf::Keyboard::Escape || event.Event::type == sf::Event::Closed)
			{
				menu_selected_flag = 0; // x.Event::type == sf::Event::Closed
			}
		}
		this->window->clear();
		menu.draw(*this->window);
		this->window->display();
	}
}




