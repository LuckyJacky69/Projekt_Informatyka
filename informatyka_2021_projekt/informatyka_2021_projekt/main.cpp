#include "Game.h"
#include "Menu.h"
#include "my_lib.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "MENU", sf::Style::Close | sf::Style::Titlebar);
    Menu menu(window.getSize().x, window.getSize().y);
    sf::Texture menu_back;
    menu_back.loadFromFile("Textures/background_menu.jpg");
    sf::Sprite S(menu_back);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            int menu_selected_flag= 0;
            float conv=1;
            if (menu_selected_flag == 0)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        my_delay(250);
                        menu.MoveUp();
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        my_delay(250);
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
                            menu.change_diff();
                            menu.getConverter(conv);
                        }

                        if (event.key.code == sf::Keyboard::Enter && menu.getPressedItem() == 2)        //load game module
                        {
                            menu_selected_flag = 1;
                        }
                        if (event.key.code == sf::Keyboard::Enter && menu.getPressedItem() == 3)        //Best scores (we can see x best scores)
                        {
                            menu_selected_flag = 1;
                            std::cout << "Best scores soon..." << std::endl;
                        }
                        if (event.key.code == sf::Keyboard::Enter && menu.getPressedItem() == 4)        //Exit
                        {
                            std::cout << "Wyjscie z gry" << std::endl;
                            window.close();
                        }
                    }
                }
            }
            if (menu_selected_flag == 1)                                                            //return from game to menu after pressing Escape
            {
                if (event.key.code == sf::Keyboard::Escape || event.Event::type == sf::Event::Closed)
                {
                    menu_selected_flag = 0; // x.Event::type == sf::Event::Closed
                }
            }
        }
        window.clear();
        window.draw(S);
        menu.draw(window);
        window.display();
    }


    return 0;
}

//Game game;
//game.run();



/*
    sf::RenderWindow window(sf::VideoMode(640, 480), "Far from home", sf::Style::Close | sf::Style::Titlebar);
    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (menu_selected_flag == 0)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        my_delay(250);
                        menu.MoveUp();
                    }

                    if (event.key.code == sf::Keyboard::Down)
                    {
                        my_delay(250);
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
                            menu_selected_flag =1;
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
                            window.close();
                        }
                    }
                }
            }
            if (menu_selected_flag == 1)                                                            //return from game to menu after pressing Escape
            {
                if (event.key.code == sf::Keyboard::Escape || event.Event::type == sf::Event::Closed)
                {
                    menu_selected_flag = 0; // x.Event::type == sf::Event::Closed
                }
            }
        }
        window.clear();
        menu.draw(window);
        window.display();
    }
    return 0;

*/





















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