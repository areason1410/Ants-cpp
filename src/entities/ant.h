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
    uint8_t m_searchRadius = 5; //lower values increases performance
    uint8_t m_moveSpeed = 150;
    Wait waitTimer;
private:
    sf::Vector2f m_direction, m_colonyCenter;
};

//#define SEARCHRADIUS2 (m_searchRadius+1)*(m_searchRadius+1)-m_searchRadius/2  //very bad
#define SEARCHRADIUS2 30
