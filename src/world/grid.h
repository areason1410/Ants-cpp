#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <math.h>
#include "cell.h"

class Grid
{
public:
    Grid(sf::RenderWindow& window);
    Cell* getCellAt(sf::Vector2f pos);
    void drawCells();
private:
    sf::Vector2f cellSize;
    sf::RenderWindow& m_window;
    std::vector<Cell> m_cells;
};