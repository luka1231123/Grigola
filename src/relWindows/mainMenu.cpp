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
    date.init(15,L"დრო", Vector2i(5,10), pos);
    screenVec=gmWrMan.getSegment(0,32,0,32);
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
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<32;j++)
        {
            
            screenVec[i][j].AssignedPos = Vector2i(448+i*18,j*18);
            screenVec[i][j].update(pos,window,isOpen);
        }
    }
    
}