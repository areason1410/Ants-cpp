#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <math.h>
#include "cell.h"
#include "../util/util.h"

enum CellAroundType
{
    Above,
    Below,
    Left,
    Right
};

class Grid
{
public:
    Grid(sf::RenderWindow& window);
    Cell* getCellAt(sf::Vector2f pos);
    void drawCells();
    Cell* cellAround(int index, CellAroundType type);
    int sample(int index, int searchRadius);
    std::vector<Cell> m_cells;
private:
    sf::Vector2f cellSize;
    sf::RenderWindow& m_window;
    int m_gridWidth, m_gridHeight;
};