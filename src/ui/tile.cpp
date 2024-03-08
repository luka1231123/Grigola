#include "tile.hpp"

void tile::init(string f, string ffr)
{
    if (!textureBack.loadFromFile(f))
    {
        //Nothing goes here...?
    }
    sp.setTexture(textureBack);
    if(ffr!="")
    {
        if(!textureFront.loadFromFile(ffr))
        {
            //skibidi
        }
        spFr.setTexture(textureFront);
    }
    filename = f;
    filenameFr = ffr;
}

void tile::update(Vector2i WindowPos, RenderWindow &window, inputManager &inp, bool isOpen)
{   
    sp.setPosition(AssignedPos.x + WindowPos.x, AssignedPos.y + WindowPos.y);
    spFr.setPosition(AssignedPos.x + WindowPos.x, AssignedPos.y + WindowPos.y);
    if(isOpen)
    {
        window.draw(sp);
        //cout<<"a";
        if(filenameFr!="")
        {
            window.draw(spFr);
            //cout<<"a";
        }   
    }
}
void tile::setFrontTexture(string f)
{
    filenameFr = f;
    if(f!="")
    {
        if(!textureFront.loadFromFile(f))
        {
            //skibidi
        }
        spFr.setTexture(textureBack);
    }
}