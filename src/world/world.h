#pragma once
#include <SFML/Graphics.hpp>

#include "colony.h"
#include "grid.h"

class World
{
public:
    World(Grid grid);
    void update(sf::RenderWindow& window);
    void addFoodAt(sf::Vector2f location);

private:
    Colony m_colony;
    Grid m_grid;

};