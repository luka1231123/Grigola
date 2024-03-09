#include "inputManager.hpp"

inputManager inputManager::instance;

inputManager& inputManager::getInstance()
{
    return instance;
}

void inputManager::processInput(RenderWindow &window)
{
    sf::Event event;
    updateMouse(window);
    //Time tm = seconds(tickInterval);
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            handleKeyPress(event.key.code);
            break;
        case sf::Event::KeyReleased:
            handleKeyRelease(event.key.code);
            break;
        default:
            break;
        }
    }
    if (tm <= sf::Time::Zero)
    {
        // Do something for the game tick
        //std::cout << "Game tick every 3 seconds!\n";
        Tick = true;
        // Reset the tick interval
        tm = sf::seconds(tickInterval);
    }else{
        Tick=false;
    }
}
void inputManager::updateMouse(RenderWindow &window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        oldIsLeftPressed = isLeftPressed;
        isLeftPressed = true;
    }
    else
    {
        oldIsLeftPressed = isLeftPressed;
        isLeftPressed = false;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        oldIsRightPressed = isRightPressed;
        isRightPressed = true;
    }
    else
    {
        oldIsRightPressed = isRightPressed;
        isRightPressed = false;
    }
    oldPos=pos;
    pos = sf::Mouse::getPosition(window);
}
Vector2i inputManager::getOldPos()
{
    return oldPos;
}
Vector2i inputManager::getPos()
{
    return pos;
}

void inputManager::handleKeyPress(sf::Keyboard::Key key)
{
    pressedKeys.insert(key);
}
void inputManager::handleKeyRelease(sf::Keyboard::Key key)
{
    pressedKeys.erase(key);
}
bool inputManager::isKeyPressed(sf::Keyboard::Key key) const
{
    return pressedKeys.find(key) != pressedKeys.end();
}
bool inputManager::isTick()
{
    return Tick;
}
void inputManager::updateTime()
{
    
    elapsed = clock.restart();
    fps = 1.0f/elapsed.asSeconds();
    oldTimeSince = timeSince;
    timeSince += elapsed;
    tm -= elapsed;
}