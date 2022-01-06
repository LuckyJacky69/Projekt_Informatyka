#include "Game.h"

//Private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(640, 480), "Far from home", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
	//frames + synch-false
}
void Game::initPlayer()
{
	this->player = new Player();
}

//Con and Des
Game::Game()
{
	this->initWindow();
	this->initPlayer();
}
Game::~Game()
{
	delete this->window;
	delete this->player;
}

//Public functions

void Game::run()
{
	while (this->window->isOpen()) 
	{
		this->update();
		this->render();
	}		
}
//closing window (x and esc)
void Game::update()
{
	sf::Event x;
	while (this->window->pollEvent(x))
	{
		if (x.Event::type == sf::Event::Closed)
			this->window->close();
		if (x.Event::KeyPressed && x.Event::key.code==sf::Keyboard::Escape)
			this->window->close();
	}
	//Movement process (Player)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		this->player->move(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		this->player->move(1.f, 0.f);

}

void Game::render()
{
	this->window->clear();
	//Draw [making a frame]
	this->player->render(*this->window);

	this->window->display();
}



