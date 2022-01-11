#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "../util/util.h"
#include <iostream>

class Ant
{
public:
    Ant(sf::Vector2f pos);
    void move(float dt, sf::Vector2u windowSize);
    bool carryingFood = false;
    bool towardsColony = false;
    sf::RectangleShape m_body;
    bool onRotationCooldown = 0;
private:
    sf::Vector2f m_direction, m_colonyCenter;
    Wait waitTimer;
};