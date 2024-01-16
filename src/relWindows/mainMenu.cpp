#include "mainMenu.hpp"

mainMenu::mainMenu() : relWindow()
{
    isOpen = true;
    height = 576;
    width = 1024;
    pos.x = 600;
    pos.y = 300;
    but.init(576,576,Vector2i(448,0),Color::White, pos);
    txt.init(22,L"",Vector2i(3,-26),pos);
    //25 3 -27 დასამახსოვრებელი რიცხვებია.
    init();
}

void mainMenu::varUpdate(RenderWindow &window, inputManager &inp)
{
    but.update(pos,window,inp,isOpen);
    wstring s = L"მთავარი ფანჯარა";
    txt.update(pos,s,window,inp,isOpen);
}