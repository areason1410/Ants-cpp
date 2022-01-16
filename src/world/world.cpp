#include "world.h"


World::World(Grid grid):
m_grid(grid),
m_colony(500) // ant count - 
{

}

void World::update(sf::RenderWindow& window)
{
    m_grid.drawCells();
    m_colony.update(m_grid, window);
}

void World::addFoodAt(sf::Vector2f location)
{
    Cell* t = m_grid.getCellAt(location);
    t->addFood();
}

void World::toggleTrails()
{
    m_grid.m_drawTrails ^= 1;
}