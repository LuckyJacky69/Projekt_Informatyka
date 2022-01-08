#include "Game.h"

//Private functions

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(640, 480), "Far from home", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
	//frames + synch-false
}
//projectile texture
void Game::initTextures()
{
	this->textures["SHOT"] = new sf::Texture();
	if (!this->textures["SHOT"]->loadFromFile("Textures/shot.png"))
		std::cout << "ERROR - file shot.png is missing." << "\n";
	
}
void Game::initGUI()
{
	//Loading font
	if(!this->font.loadFromFile("arial.ttf"))
		std::cout << "ERROR - file arial.ttf is missing." << "\n";

	//Init point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(18);
	this->pointText.setFillColor(sf::Color::White);
	//this->pointText.setString("Witam");

	this->gameoverText.setFont(this->font);
	this->gameoverText.setCharacterSize(60);
	this->gameoverText.setFillColor(sf::Color::Red);
	this->gameoverText.setPosition(sf::Vector2f(180.f, 180.f));
	this->gameoverText.setString("Gameover!");

	//Player hp' bar
	this->playerHpBar.setSize(sf::Vector2f(150.f, 10.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(0.f, 30.f));
	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(125,25,25,200));
}

void Game::initBackground()
{
	if(!this->backgroundTexture.loadFromFile("Textures/background.png"))
		std::cout << "ERROR - file background.png is missing." << "\n";
	this->background.setTexture(this->backgroundTexture);
}
void Game::initSystems()
{
	this->points = 0;
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initEnemies()
{
	this->spawnTimerMax=30.f;
	this->spawnTimer = this->spawnTimerMax;
}

//Con and Des
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initBackground();
	this->initSystems();
	this->initPlayer();
	this->initEnemies();
}
Game::~Game()
{
	delete this->window;
	delete this->player;

	//Dynamic deleting textures 
	for (auto& i : this->textures)
	{
		delete i.second;
	}

	//deleting projectiles
	for (auto* i : this->shots)
	{
		delete i;
	}
	//deleting enemies
	for (auto* i : this->enemies)
	{
		delete i;
	}

}

//Public functions

void Game::run()
{
	while (this->window->isOpen() ) 
	{
		this->updatePollEvents();

		if(this->player-> getHp() > 0)
			this->update();
		this->render();
	}		
}
//natural closing game
void Game::updatePollEvents()
{
	sf::Event x;
	while (this->window->pollEvent(x))
	{
		if (x.Event::type == sf::Event::Closed)
			this->window->close();
		if (x.Event::KeyPressed && x.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::updateInput()
{
	//Movement process (Player)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		this->player->move(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		this->player->move(1.f, 0.f);

	//shooting with space and attacking
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && this-> player->canAttack())
	{
		this->shots.push_back(new Shot(this->textures["SHOT"], this->player->getPos().x+93.f, this->player->getPos().y+20.f, 1.f, 0.f, 2.f));	
	}
}

void Game::updateGUI()

{	
	//setting points
	std::stringstream ss;
	ss << "Score: "<<this->points;
	this->pointText.setString(ss.str());
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(150.f * hpPercent, this->playerHpBar.getSize().y));

}

void Game::updateWorld()
{

}
//Player's collision with all 4 edges
void Game::updateCollision()
{
	//left edge
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}
	//right edge
	if (this->player->getBounds().left > 540.f)
	{
		this->player->setPosition(540.f, this->player->getBounds().top);
	}
	//top edge
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}
	//bottom edge
	if (this->player->getBounds().top > 434.f)
	{
		this->player->setPosition(this->player->getBounds().left, 434.f);
	}
}

void Game::updateShots()
{
	unsigned counter = 0;
	for (auto* shot : this->shots)
	{
		shot->update();

		//shot culling on the edge of right screen

		if (shot->getBounds().left + shot->getBounds().width > 640.f)
		{
			//deleting projectile (erasing memory)

			delete this->shots.at(counter);
			this->shots.erase(this->shots.begin() + counter );
			--counter;

			//checking ^std::cout <<this->shots.size() <<"\n";
		}
		++counter;
	}
}

void Game::updateEnemies()
{
	//spawning
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax) 		//when timer will reach max value, then it will decrease to 0.
	{
		this->enemies.push_back(new Enemy(600, rand() % 480));
		this->spawnTimer = 0.f;
	}
	//Update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		if (enemy->getBounds().left + enemy->getBounds().width < -100.f)
		{
			//deleting enemy (erasing memory) as they reach -100 width

			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			
			//--counter;
			//checking ^std::cout <<this->shots.size() <<"\n";
		}
		else if(enemy->getBounds().intersects(this->player->getBounds()))
		{
			//deleting enemy (erasing memory) as they interact with player's position
			this->player->loseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}

		++counter;
	}
}
void Game::updateCombat()
{

	for (int i = 0; i < this->enemies.size(); i++)			//each enemy removed by projectile 
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->shots.size() && enemy_deleted==false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->shots[k]->getBounds()))
			{
				this->points += this->enemies[i]->getPoints();

				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->shots[k];
				this->shots.erase(this->shots.begin() + k);
				enemy_deleted = true;
			}
		}
	}
}
//updating and rendering !!

void Game::update()
{

	this->updateInput();

	this->player->update();

	this->updateCollision();

	this->updateShots();

	this->updateEnemies();

	this->updateCombat();

	this->updateGUI();

	this->updateWorld();
}
void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
}

void Game::renderBackground()
{
	this->window->draw(this->background);
}

void Game::render()
{
	this->window->clear();

	//Draw Background
	this->renderBackground();

	//Draw all things
	this->player->render(*this->window);
	for (auto* shot: this->shots)
	{
		shot->render(this->window);
	}
	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}
	this->renderGUI();

	//Gameover
	if (this->player->getHp() <= 0)
		this->window->draw(this->gameoverText);

	this->window->display();
}



