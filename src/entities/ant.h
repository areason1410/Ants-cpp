#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "../util/util.h"

class Ant
{
public:
    Ant(sf::Vector2f pos);
    void move(float dt, sf::Vector2u windowSize);
    bool carryingFood = false;

    sf::RectangleShape m_body;
private:
    sf::Vector2f m_direction, m_colonyCenter;
};