#include "gameWorldManager.hpp"

gameWorldManager::gameWorldManager()
{
    tileList.resize(50, vector<tile> (50));
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            tileList[i][j].init("images/GrassPlain.png", "images/Cross.png");
        }
    }
}

gameWorldManager gameWorldManager::instance;

gameWorldManager& gameWorldManager::getInstance() 
{
    return instance;
}

vector<vector<tile>>& gameWorldManager::getSegment(int rowStart, int rowEnd, int colStart, int colEnd) {
    // Validate input indices
    std::vector<std::vector<tile>>& matrix = tileList;
    int numRows = matrix.size();
    int numCols = (numRows > 0) ? matrix[0].size() : 0;

    if (rowStart < 0 || rowEnd >= numRows || colStart < 0 || colEnd >= numCols) {
        std::cerr << "Invalid indices for segment!" << std::endl;
        // You can throw an exception here if needed
    }

    // Create a reference to the desired segment
    static std::vector<std::vector<tile>> segment;
    segment.clear(); // Clear any previous data

    for (int i = rowStart; i <= rowEnd; ++i) {
        std::vector<tile> row(matrix[i].begin() + colStart, matrix[i].begin() + colEnd + 1);
        segment.push_back(row);
    }

    return segment;
}