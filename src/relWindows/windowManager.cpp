#include "windowManager.hpp"


void windowManager::drawAndUpdate(RenderWindow &window, inputManager &inp)
{
    //top start
    switch (onTop)
    {
    case 1:
        mm.update(window, inp);
        break;
    
    default:
        break;
    }

    //sequence 
    if(onTop!=1)
    {
        mm.update(window, inp);
    }



}