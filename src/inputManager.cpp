#include "inputManager.hpp"
#include "gameManager.hpp"

using namespace sf;
using namespace std;

gameManager gm;

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
        isLeftPressed = true;
    }
    else
    {
        isLeftPressed = false;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        isRightPressed = true;
    }
    else
    {
        isRightPressed = false;
    }

    pos = sf::Mouse::getPosition(window);
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