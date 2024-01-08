#ifndef _inputManager_
#define _inputManager_

#include "gameManager.hpp"

using namespace std;
using namespace sf;

class inputManager
{
private:
    unordered_set<sf::Keyboard::Key> pressedKeys;

    void handleKeyPress(sf::Keyboard::Key key);

    void handleKeyRelease(sf::Keyboard::Key key);

    void updateMouse(RenderWindow &window);

public:
    void processInput(RenderWindow &window);

    bool isKeyPressed(sf::Keyboard::Key key) const;

    bool isLeftPressed;

    bool isRightPressed;

    Vector2i pos;
};

#endif