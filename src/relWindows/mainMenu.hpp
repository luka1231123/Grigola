#ifndef _mainMenu_
#define _mainMenu_

#include "../relWindow.hpp"
#include "../includes.hpp"
#include "../inputManager.hpp"

class mainMenu : public relWindow
{
public:
    mainMenu();
private:
    void varUpdate(RenderWindow &window, inputManager &inp) override;
    button but;
    text txt;
};

#endif