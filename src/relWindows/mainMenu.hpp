#ifndef _mainMenu_
#define _mainMenu_

#include "relWindow.hpp"
#include "../includes.hpp"

class mainMenu : public relWindow
{
public:
    mainMenu();
private:
    void varUpdate(RenderWindow &window, inputManager &inp) override;
    text txt;
    text date;
    tile til;
};

#endif