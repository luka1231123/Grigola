#ifndef _Entity_
#define _Entity_

#include "../includes.hpp"

class Entity
{
public:
    Vector2i pos;
    string front;
    string back;
private:
    void interact();
};

#endif