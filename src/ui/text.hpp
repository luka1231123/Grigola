#ifndef _text_
#define _text_

#include "../includes.hpp"
#include "../inputManager.hpp"

class text
{
public:
    void init(int fontSize, wstring contents, Vector2i AssignedPos, Vector2i WindowPos);

    void update(Vector2i WindowPos, wstring contents, RenderWindow &window, inputManager &inp, bool isOpen);

    Vector2i pos;

    int fontSize;

    string contents;

    Color color;

private:
    Text text;
    
    Font font;
};

#endif