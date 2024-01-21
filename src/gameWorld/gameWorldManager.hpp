#ifndef _gameWorldManager_
#define _gameWorldManager_

#include "../includes.hpp"
#include "Entity.hpp"
#include "../ui/tile.hpp"

class gameWorldManager
{
public:
    Entity ent[200][200];
    tile til[32][32];
    void init();
    void checks();
    void updateTileMap();
private:
    void moveFront();
};

#endif