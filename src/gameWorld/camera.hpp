#ifndef _camera_
#define _camera_

#include "../includes.hpp"
#include "worldTile.hpp"
#include "gameWorldManager.hpp"

//singleton

class camera
{
public:
    camera();
    static camera& getInstance();
    vector<vector<worldTile>> getView();
    void moveView(string dir);
    bool moved;
    // temporary
    void tempMove();
    Vector2i pos;
private:
    //temporary
    inputManager& inp = inputManager::getInstance();
    vector<vector<worldTile>> viewPort;
    static camera instance;
    gameWorldManager& gmWrl = gameWorldManager::getInstance();
};

#endif