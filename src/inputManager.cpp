#include "inputManager.hpp"

void inputManager::processInput(RenderWindow &window)
{
    sf::Event event;
    updateMouse(window);
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