#ifndef _tile_
#define _tile_

#include "../includes.hpp"
#include "../inputManager.hpp"

class tile
{
public:
    void init(string filename, string filenameFr);

    void update(Vector2i WindowPos, RenderWindow &window, bool isOpen);

    void setFrontTexture(string filenameFr);

    void setBackTexture(string filename);

    Vector2i AssignedPos;

private:
    string filenameFr;
    string filename;
    Sprite sp;
    Sprite spFr;
    Texture textureBack;
    Texture textureFront;
};

#endif