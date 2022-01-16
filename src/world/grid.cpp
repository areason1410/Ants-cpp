#include "grid.h"
#include <iostream>

Grid::Grid(sf::RenderWindow &window):
m_window(window)
{
    cellSize.x = 4;
    cellSize.y = 4;
    m_gridWidth = (m_window.getSize().x)/cellSize.x;
    m_gridHeight = (m_window.getSize().y)/cellSize.y;

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
        cell.draw(m_window, m_drawTrails);
    }
}

// i feel like this can be much better
Cell* Grid::cellAround(int index, DirectionType type)
{
    switch (type)
    {
    case DirectionType::Above:
        if(index < m_gridWidth) return &m_cells[index];
        return &m_cells[index - m_gridWidth];
        break;
    case DirectionType::Below:
        if(index > (m_gridWidth*(m_gridHeight-1))) return &m_cells[index];
        return &m_cells[index + m_gridWidth];
        break;
    case DirectionType::Right:
        if(index % m_gridWidth == 0) return &m_cells[index];
        return &m_cells[index + 1];
        break;
    case DirectionType::Left:
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
Cell* Grid::sample(int index, int searchRadius, TrailType desiredType)
{
    std::vector<Cell*> intensities;

    //this spills over a few extra but dw that
    for(int i = 0; i < searchRadius; i++)
    {
        intensities.push_back(cellAround(index-i*m_gridWidth, DirectionType::Above));      
        intensities.push_back(cellAround(index+i*m_gridWidth, DirectionType::Below));
        for(int j = 0; j < searchRadius+1; j++)
        {
            intensities.push_back(cellAround(index-i+j*m_gridWidth, DirectionType::Left));      
            intensities.push_back(cellAround(index-i-j*m_gridWidth, DirectionType::Left)); 
            intensities.push_back(cellAround(index+i+j*m_gridWidth, DirectionType::Right));
            intensities.push_back(cellAround(index+i-j*m_gridWidth, DirectionType::Right));
            
        }
        
    }

    int best = 0;
    int index2 = 0;

    for(int i = 0; i < intensities.size(); i++)
    {
        if(intensities[i]->m_trailIntensity >= best && intensities[i]->m_trailType == desiredType)
        {
            best = intensities[i]->m_trailIntensity;
            index2 = intensities[i]->m_index;
        }
    }

    if(best == 0)
    {
        static Cell dummy(1, 1, 1, 1, -1);
        return &dummy;
    }

    return &m_cells[index2];
}
