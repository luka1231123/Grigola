#ifndef _button_
#define _button_

#include "../includes.hpp"
#include "../inputManager.hpp"
#include "text.hpp"

class button
{
public:
    void init(int h, int w, Vector2i AssignedPos, Color cl, Vector2i WindowPos);

    void update(Vector2i WindowPos, RenderWindow &window, inputManager &inp, bool isOpen);

    bool isHovered;

    bool isClicked;

    Vector2i pos;

    int height;

    int width;

    Color color;

private:
    RectangleShape button;
};

#endif