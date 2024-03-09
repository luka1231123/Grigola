#include "button.hpp"

void button::init(int h, int w, Vector2i AssignedPos, Color cl, Vector2i WindowPos)
{
    height = h;
    width = w;
    color = cl;
    pos = Vector2i(AssignedPos.x, AssignedPos.y);
    
    button.setSize(Vector2f(width, height));
    button.setFillColor(color);
    button.setPosition(pos.x + WindowPos.x, pos.y + WindowPos.y);
}

void button::update(Vector2i WindowPos, RenderWindow &window, bool isOpen)
{
    // run after init
    //pos = Vector2i(pos.x, pos.y);
    //cout << WindowPos.x << endl;
    button.setPosition(pos.x + WindowPos.x, pos.y + WindowPos.y);


    if (isOpen && inp.isLeftPressed && !inp.oldIsLeftPressed && inp.getPos().x > button.getPosition().x && inp.getPos().x < button.getPosition().x + width && inp.getPos().y > button.getPosition().y && inp.getPos().y < button.getPosition().y+height)
    {
        isClicked = true;
    }
    else
    {
        isClicked = false;
    }
    if (isOpen && inp.getPos().x > button.getPosition().x && inp.getPos().x < button.getPosition().x + width && inp.getPos().y > button.getPosition().y && inp.getPos().y < button.getPosition().y+height)
    {
        isHovered = true;
    }
    else
    {
        isHovered = false;
    }
    if(isOpen)
    {
        window.draw(button);
    }
}