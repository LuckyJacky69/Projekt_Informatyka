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
class Game
{
private:
	//window
	sf::RenderWindow* window;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Shot*> shots;							//Shot* because we are creating new projectiles, not copying 1.
	FILE* fp;

	//GUI
	sf::Font font;
	sf::Text pointText;
	sf::Text gameoverText;
	sf::Text continueText;
	sf::Text continueText_1;
	sf::Text helpText;
	sf::Text helpText_1;
	sf::Text helpText_2;
	sf::Text helpText_3;
	sf::Text helpText_4;
	//Hp bar
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//Background
	sf::Texture backgroundTexture;
	sf::Sprite background;
	
	//collision explosion

	sf::RectangleShape help;							//pressing F1 or Esc (background)

	//System
	unsigned points;	
	int play = 1;
	float player_hp;

	//creating player
	Player* player;
	double converter=1;

	//Enemy
	float spawnTimer;		
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	void initWindow();
	void initTextures();
	void initGUI();
	void initBackground();
	void initPlayer();
	void initEnemies();

public:
	Game();
	virtual ~Game();

	void file_load();
	void file_save();
	void run(double converter);
	void run_load(double converter);
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
	void renderBoom();
	void renderBackground();
	void render();
};

