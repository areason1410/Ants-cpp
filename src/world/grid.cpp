#include "grid.h"
#include <iostream>

Grid::Grid(sf::RenderWindow &window):
m_window(window)
{
    cellSize.x = 6;
    cellSize.y = 6;
    m_gridWidth = m_window.getSize().x/cellSize.x;
    m_gridHeight = m_window.getSize().y/cellSize.y;

    for(int i = 0; i < m_gridHeight; i++)
    {
        for(int j = 0; j < m_gridWidth; j++)
        {
            Cell cell(cellSize.x, cellSize.y, j*cellSize.x, i*cellSize.y, (i*m_gridWidth + j));
            m_cells.push_back(cell);
        }
    }
    std::cout << m_cells.size() << "\n";

}


Cell* Grid::getCellAt(sf::Vector2f pos)
{
    float x = pos.x <= 0 ? 0 : (int)(pos.x/cellSize.x);
    float y = pos.y <= 0 ? 0 : (int)(pos.y/cellSize.y);

    int lF = (int)( x + y * m_gridWidth);
    return &m_cells[lF];
}


void Grid::drawCells()
{
    for(Cell &cell: m_cells)
    {
        cell.draw(m_window);
    }
}


Cell* Grid::cellAround(int index, CellAroundType type)
{
    switch (type)
    {
    case CellAroundType::Above:
        if(index < m_gridWidth) return &m_cells[index];
        return &m_cells[index - m_gridWidth];
        break;
    case CellAroundType::Below:
        if(index > (m_gridWidth*(m_gridHeight-1))) return &m_cells[index];
        return &m_cells[index + m_gridWidth];
        break;
    case CellAroundType::Right:
        if(index % m_gridWidth == 0) return &m_cells[index];
        return &m_cells[index + 1];
        break;
    case CellAroundType::Left:
        if((index - 1 ) % m_gridWidth  == 0 ) return &m_cells[index];
        return &m_cells[index - 1];
        break;
    default:
        break;
    }
}

 
//there is probably a more efficient way but this works soooo
// rn just making a trail cuz why not
// current bug with that: it creates streaks of trail down the screen. Gotta fix probs to do with my cellAround function.
int Grid::sample(int index, int searchRadius)
{
    std::vector<sf::Vector2i> intensities;

    for(int i = 0; i < searchRadius; i++)
    {
        cellAround(index-i*m_gridWidth, CellAroundType::Above)->makeTrail() ;      
        cellAround(index+i*m_gridWidth, CellAroundType::Below)->makeTrail() ;
        for(int j = 0; j < searchRadius+1; j++)
        {
            cellAround(index-i+j*m_gridWidth, CellAroundType::Left)->makeTrail() ;      
            cellAround(index-i-j*m_gridWidth, CellAroundType::Left)->makeTrail() ;      
            cellAround(index+i+j*m_gridWidth, CellAroundType::Right)->makeTrail() ;
            cellAround(index+i-j*m_gridWidth, CellAroundType::Right)->makeTrail() ;

        }     
        
    }
    return 1;
}