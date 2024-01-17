#ifndef _tile_
#define _tile_

#include "../includes.hpp"
#include "../inputManager.hpp"

class tile
{
public:
    void init(string filename, string filenameFr, Vector2i AssignedPos, Vector2i WindowPos);

    void update(Vector2i WindowPos, RenderWindow &window, inputManager &inp, bool isOpen);

    void setFrontTexture(string filenameFr);

    Vector2i pos;

    string filename;

    string filenameFr;

    Color color;
    

private:
    Sprite sp;
    Sprite spFr;
    Texture textureBack;
    Texture textureFront;
};

#endif