#include "gameWorldManager.hpp"

gameWorldManager::gameWorldManager()
{
    tileList.resize(5000, vector<worldTile> (5000));
    for(int i=0;i<5000;i++)
    {
        for(int j=0;j<5000;j++)
        {
            if(rand()%5==1)
            {
                tileList[i][j].background = "images/GrassArid.png";
            }else
            {
                tileList[i][j].background = "images/GrassPlain.png";
            }
        }
    }
}

gameWorldManager gameWorldManager::instance;

gameWorldManager& gameWorldManager::getInstance() 
{
    return instance;
}