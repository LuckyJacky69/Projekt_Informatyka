#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string>
#include <vector>
#include <array>
#include <fstream>

#include "Player.h";

class Game
{
private:
	//creating player
	Player* player;
	sf::RenderWindow* window;
	void initWindow();
	void initPlayer();

public:
	Game();
	virtual ~Game();

	// Metody
	void run();
	void update();
	void render();
};

