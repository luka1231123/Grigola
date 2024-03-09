#ifndef _text_
#define _text_

#include "../includes.hpp"
#include "../inputManager.hpp"

class text
{
public:
    void init(int fontSize, wstring c, Vector2i AssignedPos, Vector2i WindowPos);

    void update(Vector2i WindowPos, RenderWindow &window, bool isOpen);

    Vector2i pos;

    int fontSize;

    wstring contents;

    Color color;

private:
    Text text;
    
    inputManager& inp = inputManager::getInstance();
    
    Font font;
};

#endif