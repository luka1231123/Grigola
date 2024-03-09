#ifndef _mainMenu_
#define _mainMenu_

#include "relWindow.hpp"
#include "../includes.hpp"
#include "../gameWorld/camera.hpp"


class mainMenu : public relWindow
{
public:
    mainMenu();
    
private:
    void varUpdate(RenderWindow &window) override;
    camera& cam = camera::getInstance();
    gameWorldManager& gmWrld = gameWorldManager::getInstance();
    vector <vector <tile>> viewPort;
    text txt;
    text date;
    void updateViewPort();
};

#endif