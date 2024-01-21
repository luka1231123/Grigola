#ifndef _relWindow_
#define _relWindow_

#include "../ui/button.hpp"
#include "../ui/text.hpp"
#include "../ui/tile.hpp"
#include "../includes.hpp"

class relWindow
{
public:
    relWindow();
    
    sf::Vector2i pos;

    int height;

    int width;
    
    bool isOpen;

    void update(sf::RenderWindow &window, inputManager &inp);

    sf::Vector2i relativeMouseLoc(inputManager &inp);

    void init();

private:

    virtual void varUpdate(RenderWindow &window, inputManager &inp);

    bool isMoving;

    int xOffset;

    button titleBar;

    button closeButton;

    sf::RectangleShape background;
};

#endif