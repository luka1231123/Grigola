#include "camera.hpp"

camera camera::instance;

camera& camera::getInstance()
{
    return instance;
}

camera::camera()
{
    pos = Vector2i(17,16);
}
//slow solution
void camera::moveView(string dir)
{
    moved=true;
    if(dir=="right")
    {
        pos.x+=1;
    }
    if(dir=="left" && pos.x>16)
    {
        pos.x-=1;
    }
    if(dir=="up" && pos.y>16)
    {
        pos.y-=1;
    }
    if(dir=="down")
    {
        pos.y+=1;
    }
}
//this shouldn't be here
void camera::tempMove()
{
    
    if(inp.isKeyPressed(Keyboard::Key::D))
    {
        gmWrl.inputLine.push(Keyboard::Key::D);
    }
    if(inp.isKeyPressed(Keyboard::Key::A))
    {
        gmWrl.inputLine.push(Keyboard::Key::A);
    }
    if(inp.isKeyPressed(Keyboard::Key::W))
    {
        gmWrl.inputLine.push(Keyboard::Key::W);
    }
    if(inp.isKeyPressed(Keyboard::Key::S))
    {
        gmWrl.inputLine.push(Keyboard::Key::S);
    }
    
    if(inp.isTick())
    {
        Keyboard::Key first=gmWrl.inputLine.front();
        gmWrl.inputLine.pop();
        Keyboard::Key second=gmWrl.inputLine.front();

        if(first == Keyboard::Key::D && second==Keyboard::Key::W)
        {
            moveView("right");
            moveView("up");
        }
        if(first == Keyboard::Key::D && second==Keyboard::Key::D)
        {
            moveView("right");
        }
        if(first == Keyboard::Key::D && second==Keyboard::Key::S)
        {
            moveView("right");
            moveView("down");
        }
        if(first == Keyboard::Key::A && second==Keyboard::Key::W)
        {
            moveView("left");
            moveView("up");
        }
        if(first == Keyboard::Key::A && second==Keyboard::Key::A)
        {
            moveView("left");
        }
        if(first == Keyboard::Key::A && second==Keyboard::Key::S)
        {
            moveView("left");
            moveView("down");
        }
        if(first == Keyboard::Key::W && second==Keyboard::Key::W)
        {
            moveView("up");
        }
        if(first == Keyboard::Key::S && second==Keyboard::Key::S)
        {
            moveView("down");
        }
        queue <Keyboard::Key> empty;
        swap(gmWrl.inputLine, empty);   
    }
    
}