#ifndef _mainMenu_
#define _mainMenu_

#include "relWindow.hpp"
#include "../includes.hpp"
#include "../gameWorld/gameWorldManager.hpp"


class mainMenu : public relWindow
{
public:
    mainMenu();
private:
    void varUpdate(RenderWindow &window) override;
    gameWorldManager& gmWrMan = gameWorldManager::getInstance();
    text txt;
    vector<vector<tile>> screenVec;
    text date;
};

#endif