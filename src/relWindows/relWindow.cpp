#include "relWindow.hpp"


relWindow::relWindow()
{
}
void relWindow::init()
{
    background.setSize(Vector2f(width, height));
    background.setFillColor(sf::Color::Black);
    background.setPosition(pos.x, pos.y);
    titleBar.init(25, width-25, Vector2i(0, -25), Color(50, 50, 50), pos);
    closeButton.init(25, 25, Vector2i(width-25, -25), Color(175, 50, 50), pos);
}

void relWindow::update(RenderWindow &window, inputManager &inp)
{
    if(isOpen)
    {
        window.draw(background);
    }
    
    background.setPosition(pos.x, pos.y);
    background.setSize(Vector2f(width, height));
    titleBar.update(pos, window, inp, isOpen);
    closeButton.update(pos, window, inp, isOpen);
    varUpdate(window,inp);
    if (closeButton.isClicked)
    {
        isOpen = false;
    }
    if (titleBar.isClicked && !isMoving)
    {
        isMoving = true;
        xOffset = relativeMouseLoc((inp)).x;
    }
    if(isMoving && inp.isLeftPressed)
    {        
        pos.x = inp.getPos().x-xOffset;
        pos.y = inp.getPos().y+12;
    }else{
        isMoving = false;
    }
}
void relWindow::varUpdate(RenderWindow &window, inputManager &inp)
{
}

Vector2i relWindow::relativeMouseLoc(inputManager &inp)
{
    Vector2i newPos;
    newPos.x = inp.getPos().x - background.getPosition().x;
    newPos.y = inp.getPos().y - background.getPosition().y;
    return newPos;
}