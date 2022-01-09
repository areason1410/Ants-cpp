#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../entities/ant.h"
#include "grid.h"
#include <iostream>


class Colony
{
public:
    Colony(int antCount);
    void update(Grid& grid, sf::RenderWindow& window);
    std::vector<Ant> ants;
    float dt;
private:
    sf::Clock m_clock;
    sf::CircleShape m_colonyBody;
    int m_antCount;

};