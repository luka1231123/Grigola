#include "tile.hpp"

void tile::init(string f, string ffr, Vector2i AssignedPos, Vector2i WindowPos)
{
    pos = Vector2i(AssignedPos.x, AssignedPos.y);
    if (!textureBack.loadFromFile(f))
    {
        //Nothing goes here...?
    }
    sp.setTexture(textureBack);
    sp.setPosition(pos.x + WindowPos.x, pos.y + WindowPos.y);
    if(ffr!="")
    {
        if(!textureFront.loadFromFile(ffr))
        {
            //skibidi
        }
        spFr.setTexture(textureFront);
        spFr.setPosition(pos.x + WindowPos.x, pos.y + WindowPos.y);
    }
    filename = f;
    filenameFr = ffr;
}

void tile::update(Vector2i WindowPos, RenderWindow &window, inputManager &inp, bool isOpen)
{   
    sp.setPosition(pos.x + WindowPos.x, pos.y + WindowPos.y);
    spFr.setPosition(pos.x + WindowPos.x, pos.y + WindowPos.y);
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