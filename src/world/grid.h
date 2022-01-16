#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <math.h>
#include "cell.h"
#include "../util/util.h"
#include <tuple>


class Grid
{
public:
    Grid(sf::RenderWindow& window);
    Cell* getCellAt(sf::Vector2f pos);
    void drawCells();
    Cell* cellAround(int index, DirectionType type);
    Cell* sample(int index, int searchRadius, TrailType desiredType);
    std::vector<Cell> m_cells;
    bool m_drawTrails;
  

private:
    sf::Vector2f cellSize;
    sf::RenderWindow& m_window;
    int m_gridWidth, m_gridHeight;
};