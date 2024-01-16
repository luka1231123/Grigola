#include "mainMenu.hpp"

mainMenu::mainMenu() : relWindow()
{
    isOpen = true;
    height = 576;
    width = 1024;
    pos.x = 960;
    pos.y = 540;
    but.init(576,576,Vector2i(448,0),Color::White, pos);
    txt.init(22,L"",Vector2i(3,-26),pos);
    //25 3 -27 დასამახსოვრებელი რიცხვებია.
    init();
}

void mainMenu::varUpdate(RenderWindow &window, inputManager &inp)
{
    but.update(pos,window,inp,isOpen);
    txt.update(pos,L"მთავარი ფანჯარა",window,inp,isOpen);
}