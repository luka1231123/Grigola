#ifndef _gameManager_
#define _gameManager_

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <SFML/Graphics.hpp>
#include "inputManager.hpp"

using namespace sf;
using namespace std;

class gameManager
{
public:
	void run();
	string gameState;
	RenderWindow window;

private:
	void init(RenderWindow &Window);
	void mainLoop(RenderWindow &Window);
};

#endif