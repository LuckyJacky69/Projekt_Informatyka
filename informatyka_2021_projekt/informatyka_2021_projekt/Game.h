#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <sstream>
#include <map>
#include <math.h>
#include "Player.h"
#include "Shot.h"
#include "Enemy.h"
#include "Menu.h"

class Game
{
private:
	//window
	sf::RenderWindow* window;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Shot*> shots;							//Shot* because we are creating new projectiles, not copying 1.

	//GUI
	sf::Font font;
	sf::Text pointText;
	sf::Text gameoverText;
	//Hp bar
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//Background
	sf::Texture backgroundTexture;
	sf::Sprite background;

	//System
	unsigned points;

	//creating player
	Player* player;

	//Enemy
	float spawnTimer;		
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	void initWindow();
	void initTextures();
	void initGUI();
	void initBackground();
	void initSystems();
	void initPlayer();
	void initEnemies();

public:
	Game();
	virtual ~Game();

	// functions
	void run();
	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateShots();
	void updateEnemies();
	void updateCombat();
	void update();
	void renderGUI();
	void renderBackground();
	void render();
};

