#ifndef _gameWorldManager_
#define _gameWorldManager_

#include "../includes.hpp"
#include "worldTile.hpp"

//singleton

class gameWorldManager
{
public:
	static gameWorldManager& getInstance();
	vector<vector<worldTile>> tileList;
	queue<Keyboard::Key> inputLine;
private:
	gameWorldManager();
	static gameWorldManager instance;
	inputManager& inp = inputManager::getInstance();
};

#endif