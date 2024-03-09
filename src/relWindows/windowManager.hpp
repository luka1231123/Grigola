#ifndef _windowManager_
#define _windowManager_

#include "../includes.hpp"
#include "mainMenu.hpp"

class windowManager
{
public:
    void drawAndUpdate(RenderWindow &window);
private:
    int onTop;
    mainMenu mm;
};

#endif