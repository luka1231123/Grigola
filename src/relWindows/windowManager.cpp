#include "windowManager.hpp"


void windowManager::drawAndUpdate(RenderWindow &window)
{
    //top start
    switch (onTop)
    {
    case 1:
        mm.update(window);
        break;
    
    default:
        break;
    }

    //sequence 
    if(onTop!=1)
    {
        mm.update(window);
    }
}