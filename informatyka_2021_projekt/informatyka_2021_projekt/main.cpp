#include "Game.h"
#include "Menu.h"
int main()
{
    double converter=1;
    sf::RenderWindow window(sf::VideoMode(640, 480), "MENU", sf::Style::Close | sf::Style::Titlebar);
    Menu menu(window.getSize().x, window.getSize().y, &converter);
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

            int menu_selected_flag = 0;
            if (menu_selected_flag == 0)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        menu.initDelay(250);
                        menu.MoveUp();
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        menu.initDelay(250);
                        menu.MoveDown();
                    }
                    if (menu_selected_flag == 0)
                    {
                        if (event.key.code == sf::Keyboard::Enter && menu.getPressedItem() == 0)        //PLAY
                        {
                            Game game;
                            game.run(converter);
                        }

                        if (event.key.code == sf::Keyboard::Enter && menu.getPressedItem() == 1)        //Difficulty level inside
                        {                                              
                            menu.change_diff();
                        }

                        if (event.key.code == sf::Keyboard::Enter && menu.getPressedItem() == 2)        //load game module
                        {                      
                            Game game;
                            game.run_load(converter);
                        }

                        if (event.key.code == sf::Keyboard::Enter && menu.getPressedItem() == 3)        //Best scores (we can see x best scores)
                        {
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
