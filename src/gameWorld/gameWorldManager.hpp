#ifndef _gameWorldManager_
#define _gameWorldManager_

#include "../includes.hpp"
#include "../ui/tile.hpp"

class gameWorldManager
{
public:
	
	vector<vector<tile>>& getSegment(int rowStart, int rowEnd, int colStart, int colEnd);
	static gameWorldManager& getInstance();
private:
	gameWorldManager();
	vector<vector<tile>> tileList;
	static gameWorldManager instance;
};

#endif