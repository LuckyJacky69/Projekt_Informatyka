#include "Game.h"

int main()
{
	srand(time(NULL));

	Game game;
	game.run();
	return 0;
}




























/*

	//okno
	sf::RenderWindow window(sf::VideoMode(640, 480), "Far from home", sf::Style::Close);
	sf::Event event;

	//Pêtla
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if(event.key.code==sf::Keyboard::Escape)
					window.close();
					break;
			}
		}
	}
//Update

//Render
	window.clear();
	window.display();

*/