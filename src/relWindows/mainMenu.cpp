#include "mainMenu.hpp"

mainMenu::mainMenu() : relWindow()
{
    
    isOpen = true;
    height = 576;
    width = 1024;
    pos.x = 600;
    pos.y = 300;
    //576 576, 448
    txt.init(22,L"მთავარი ფანჯარა",Vector2i(3,-26),pos);
    date.init(20,L"დრო", Vector2i(5,10), pos);
    viewPort.resize(32, vector<tile> (32));
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<32;j++)
        {
            viewPort[i][j].init("images/GrassPlain.png", "");
            viewPort[i][j].AssignedPos = Vector2i(448+i*18,j*18);
        }
    }
    updateViewPort();
    //22 3 -26 დასამახსოვრებელი რიცხვებია.
    init();
}

void mainMenu::varUpdate(RenderWindow &window)
{
    wstring dro = L"დრო: ";
    wstring dt = to_wstring((int)inp.timeSince.asSeconds());
    dro = dro+dt;
    date.contents=dro;
    date.update(pos,window,isOpen);
    txt.update(pos,window,isOpen);
    cam.tempMove();
    if(cam.moved && inp.isTick())
    {
        updateViewPort();
        cam.moved=false;
    }
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<32;j++)
        {
            viewPort[i][j].update(pos,window,isOpen);
        }
    }
    
}

void mainMenu::updateViewPort()
{
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<32;j++)
        {
            viewPort[i][j].setBackTexture(gmWrld.tileList[i+(cam.pos.x-16)][j+(cam.pos.y-16)].background);
        }
    }
}