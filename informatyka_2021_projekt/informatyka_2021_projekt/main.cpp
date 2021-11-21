#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LICZBA_POZIOMOW 5
class ship
{
private:
    sf::Vector2f position;//wspolrzedne
    float xVel = 10;//predkosc w poziomie
    float yVel = 10;//predkosc w pionie
    sf::RectangleShape player;//prostokat jako sprite??

public:
    ship(float x_in, float y_in);//tworz pilke w polozeniu (x,y)
    void przesun(float x_in, float y_in);//przesun pr
    void reset();
    void getTexture();

    sf::RectangleShape getPilka() { return player; }//zwroc pr
    sf::Vector2f getPos() { return player.getPosition(); }
};
ship::ship(float x_in, float y_in)
{
    position.x = x_in;
    position.y = y_in;
    //pr
    player.setSize(sf::Vector2f(69, 32));
    player.setPosition(position);//pozycja poczatkowa
}
class pilka {
private:
    sf::Vector2f position;//wspolrzedne
    float xVel = 10;//predkosc w poziomie
    float yVel = 10;//predkosc w pionie
    sf::CircleShape ball;//pilka

public:
    pilka(float x_in, float y_in);//tworz pilke w polozeniu (x,y)
    void przesun(float x_in, float y_in);//przesun pilke
    void reset();

    sf::CircleShape getPilka() { return ball; }//zwroc pilke
    sf::Vector2f getPos() { return ball.getPosition(); }
};

pilka::pilka(float x_in, float y_in)
{
    position.x = x_in;
    position.y = y_in;
    //kolo
    ball.setRadius(40);
    ball.setFillColor(sf::Color(0, 255, 0));
    // obramowka kola 
    ball.setOutlineThickness(2);
    ball.setOutlineColor(sf::Color(0, 150, 100));
    ball.setPosition(position);//pozycja poczatkowa
}


void pilka::przesun(float x_in, float y_in)
{
    sf::Vector2f pos;
    pos.x = x_in;
    pos.y = y_in;
    ball.move(pos);
}
void ship::przesun(float x_in, float y_in)
{
    sf::Vector2f pos;
    pos.x = x_in;
    pos.y = y_in;
    player.move(pos);
}

void pilka::reset() {
    this->ball.setPosition(0, 0);
}

class Menu
{

private:
    sf::Font font;
    sf::Text menu[MAX_LICZBA_POZIOMOW];//maksymalna liczba poziomow
    int selectedItem = 0;
public:
    Menu(float width, float height);
    ~Menu() {};
    void przesunG();//przesun do gory
    void przesunD();//przesun w dol
    int getSelectedItem() { return selectedItem; }
    void draw(sf::RenderWindow& window);//rysuj menu w oknie
};


Menu::Menu(float width, float height)
{	//laduj czcionke
    if (!font.loadFromFile("arial.ttf"))
    {
        return;
    }
    //menu
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Green);
    menu[0].setString("Start");
    menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Wczytaj gre");
    menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Tabela wynikow");
    menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 3));

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Pomoc");
    menu[3].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 4));

    menu[4].setFont(font);
    menu[4].setFillColor(sf::Color::White);
    menu[4].setString("Wyjscie");
    menu[4].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 5));

}

//rysowanie menu 
void Menu::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < MAX_LICZBA_POZIOMOW; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::przesunG()
{
    if (selectedItem >= 0 && selectedItem < MAX_LICZBA_POZIOMOW)
    {
        menu[selectedItem].setFillColor(sf::Color::White);
        menu[selectedItem].setStyle(sf::Text::Regular);
        selectedItem--;
        if (selectedItem < 0)
            selectedItem = MAX_LICZBA_POZIOMOW - 1;
        menu[selectedItem].setFillColor(sf::Color::Green);
        menu[selectedItem].setStyle(sf::Text::Bold);
    }
}

void Menu::przesunD()
{
    if (selectedItem >= 0 && selectedItem < MAX_LICZBA_POZIOMOW)
    {
        menu[selectedItem].setFillColor(sf::Color::White);
        menu[selectedItem].setStyle(sf::Text::Regular);
        selectedItem++;
        if (selectedItem >= MAX_LICZBA_POZIOMOW)
            selectedItem = 0;
        menu[selectedItem].setFillColor(sf::Color::Green);
        menu[selectedItem].setStyle(sf::Text::Bold);
    }
}
class pomoc
{

private:
    sf::Font font;
    sf::Text menu[MAX_LICZBA_POZIOMOW];//maksymalna liczba poziomow
    int selectedItem = 0;


public:
    pomoc(float width, float height);
    ~pomoc() {};

    void draw(sf::RenderWindow& window);
};

pomoc::pomoc(float width, float height)
{	//czcionka
    if (!font.loadFromFile("arial.ttf"))
    {
        return;
    }
    // menu
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Prowadzisz statek kosmiczny niszcz lub\nunikaj astereoidy i zbieraj zlote monety!\nSterujesz klawiszami W, A, S, D, masz\nmozliwosc strzelania klawiszem - spacja.\nWraz z uplywem czasu Twoj wynik rosnie w gore.\nMozesz tego dokonac rowniez poprzez zbieranie\nmonet!");
    menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 1));
}

//rysowanie menu
void pomoc::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < MAX_LICZBA_POZIOMOW; i++)
    {
        window.draw(menu[i]);
    }
}
//delay
void myDelay(int opoznienie)
{
    sf::Clock zegar;
    sf::Time czas;
    while (1)
    {
        czas = zegar.getElapsedTime();
        if (czas.asMilliseconds() > opoznienie)
        {
            zegar.restart();
            break;
        }
    }
}
int main()
{

    srand(time(NULL));
    int menu_selected_flag = 0;
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML", sf::Style::Close);
    Menu menu(window.getSize().x, window.getSize().y);
    pomoc pom(window.getSize().x, window.getSize().y);
    sf::Texture player_ship;
    player_ship.loadFromFile("player.png"); // tekstura shipu playera
    sf::Sprite player(player_ship, sf::IntRect(0, 0, 69, 32));
    sf::Texture background;
    background.loadFromFile("images/space.jpg"); //t³o???
    sf::Sprite b(background);
    //obiekty
    pilka p1(0, 0);
    pilka p2(0, 0);
    pilka p3(0, 0);
    pilka p4(0, 0);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (menu_selected_flag == 0)
            {
                if (event.type == sf::Event::KeyPressed) {//obsluga menu z poziomu klawiszy (strzalki)
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        myDelay(250);
                        menu.przesunG();
                    }

                    if (event.key.code == sf::Keyboard::Down)
                    {
                        myDelay(250);
                        menu.przesunD();
                    }
                    if (menu_selected_flag == 0)
                    {                                                                                   // wybor poziomu menu przez enter
                        if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 0)
                        {

                            p1.reset();
                            p2.reset();
                            p3.reset();
                            p4.reset();
                            p1.przesun((rand() % 760) + 20, (rand() % 560) + 20);
                            p2.przesun((rand() % 760) + 20, (rand() % 560) + 20);
                            p3.przesun((rand() % 760) + 20, (rand() % 560) + 20);
                            p4.przesun((rand() % 760) + 20, (rand() % 560) + 20);
                            menu_selected_flag = 1;
                        }

                        if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 3)
                        {
                            std::cout << "POMOC" << std::endl;
                            menu_selected_flag = 4;
                        }

                        if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 4)
                        {
                            std::cout << "Koniec gry" << std::endl;
                            window.close();
                        }
                    }
                }
            }
            else if (menu_selected_flag == 1)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
                    p1.przesun(0, -10);
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
                    p1.przesun(0, 10);
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
                    p1.przesun(-10, 0);
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
                    p1.przesun(10, 0);
                //powrot
                if (event.key.code == sf::Keyboard::Escape)
                {
                    menu_selected_flag = 0;
                }
            }
            //powrot
            else if (menu_selected_flag == 4)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    menu_selected_flag = 0;
                }
            }
        }
        window.clear();

        if (menu_selected_flag == 0)
            menu.draw(window);
        else if (menu_selected_flag == 1)
        {
            window.draw(p1.getPilka());
            window.draw(p2.getPilka());
            window.draw(p3.getPilka());
            window.draw(p4.getPilka());
        }
        else if (menu_selected_flag == 4)
        {
            pom.draw(window);
        }
        // wyswietl okno wraz zawartoscia
        window.display();
    }

    return 0;
}