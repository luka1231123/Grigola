#include "text.hpp"

void text::init(int fontSize, wstring c, Vector2i AssignedPos, Vector2i WindowPos)
{
    pos = Vector2i(AssignedPos.x, AssignedPos.y);
    if (!font.loadFromFile("cons.ttf"))
    {
        //Nothing goes here...?
    }
    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setFillColor(Color::White);
    text.setString(contents);
    text.setPosition(pos.x + WindowPos.x, pos.y + WindowPos.y);
    contents = c;
}

void text::update(Vector2i WindowPos, RenderWindow &window, bool isOpen)
{
    // run after init
    //pos = Vector2i(pos.x, pos.y);
    text.setString(contents);
    text.setPosition(pos.x + WindowPos.x, pos.y + WindowPos.y);

    if(isOpen)
    {
        window.draw(text);
    }
}
