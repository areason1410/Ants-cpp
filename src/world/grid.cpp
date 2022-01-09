#include "grid.h"
#include <iostream>

Grid::Grid(sf::RenderWindow &window):
m_window(window)
{
    cellSize.x = 5;
    cellSize.y = 5;

    for(int i = 0; i < m_window.getSize().y/cellSize.y; i++)
    {
        for(int j = 0; j < m_window.getSize().x/cellSize.x; j++)
        {
            Cell cell(cellSize.x, cellSize.y, j*cellSize.x, i*cellSize.y);
            m_cells.push_back(cell);
        }
    }

}


Cell* Grid::getCellAt(sf::Vector2f pos)
{
    float x = pos.x <= 0 ? 0 : (int)(pos.x/cellSize.x);
    float y = pos.y <= 0 ? 0 : (int)(pos.y/cellSize.y);

    int lF = (int)( x + y * m_window.getSize().x/cellSize.x);
    return &m_cells[lF];
}


void Grid::drawCells()
{
    for(Cell &cell: m_cells)
    {
        cell.draw(m_window);
    }
}
 