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

    bool Tick;

    Time tm = seconds(0.0f);

    Clock clock;

    Time elapsed;

    static inputManager instance;
public:
    static inputManager& getInstance();

    void processInput(RenderWindow &window);

    bool isKeyPressed(sf::Keyboard::Key key) const;

    void updateTime();

    bool isLeftPressed;

    bool oldIsLeftPressed;

    bool isRightPressed;
    
    bool oldIsRightPressed;

    float tickInterval = 0.125f;

    Time timeSince;

    float fps;

    Time oldTimeSince;
        
    Vector2i getOldPos();

    Vector2i getPos();
    
    bool isTick();
};

#endif