#ifndef _inputManager_
#define _inputManager_

#include "includes.hpp"

using namespace std;
using namespace sf;

class inputManager
{
private:
    unordered_set<sf::Keyboard::Key> pressedKeys;

    void handleKeyPress(sf::Keyboard::Key key);

    void handleKeyRelease(sf::Keyboard::Key key);

    void updateMouse(RenderWindow &window);

    Vector2i pos;

    Vector2i oldPos;

public:
    void processInput(RenderWindow &window);

    bool isKeyPressed(sf::Keyboard::Key key) const;

    bool isLeftPressed;

    bool oldIsLeftPressed;

    bool isRightPressed;
    
    bool oldIsRightPressed;

    Vector2i getOldPos();

    Vector2i getPos();
};

#endif