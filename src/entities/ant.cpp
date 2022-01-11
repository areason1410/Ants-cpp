#include "ant.h"


Ant::Ant(sf::Vector2f pos):
waitTimer(0.25)
{
    m_colonyCenter = pos;
    sf::Vector2f size;
    size.x = 2;
    size.y = 5;
    m_body.setSize(size);
    m_body.setPosition(pos.x, pos.y);
    m_body.setRotation(rand() % 360);
    m_body.setOrigin(size.x/2, size.y/2);
    // m_body.setFillColor(sf::Color::Red);
    m_body.setFillColor(sf::Color(ranged_rand(0, 255), ranged_rand(0,255), ranged_rand(0,255)));
    m_direction.x = sin(degToRad(m_body.getRotation()));
    m_direction.y = -cos(degToRad(m_body.getRotation()));
}

void Ant::move(float dt, sf::Vector2u windowSize)
{
    waitTimer.m_duration = ranged_rand(0.25f, .5f);
    float deltaTime = dt * 75;
    onRotationCooldown = 1 - waitTimer.update(dt);


     if(m_body.getPosition().x < 5.0f || m_body.getPosition().x > windowSize.x - 5) m_body.setPosition(m_colonyCenter.x, m_colonyCenter.y);
     if(m_body.getPosition().y < 5.0f || m_body.getPosition().y > windowSize.y - 5) m_body.setPosition(m_colonyCenter.x, m_colonyCenter.y);

    //if(m_body.getPosition().x < 5.0f || m_body.getPosition().x > windowSize.x - 5) m_body.setRotation(m_body.getRotation() + 180);
    //if(m_body.getPosition().y < 5.0f || m_body.getPosition().y > windowSize.y - 5) m_body.setRotation(m_body.getRotation() + 180);

    if(carryingFood == false || carryingFood == true ) //remove the or after im done testing
    {
        if(!onRotationCooldown)
        {
            m_body.setRotation(m_body.getRotation() + ranged_rand(-5, 6));

        }
            m_direction.x = sin(degToRad(m_body.getRotation()));
            m_direction.y = -cos(degToRad(m_body.getRotation()));
    }

    //uncomment when doing foodstuff again
    // if(carryingFood == true)
    // {
    //     m_body.setOutlineThickness(2);
    //     m_body.setOutlineColor(sf::Color::Green);
    //     float angleToColony = angleAB(m_colonyCenter, m_body.getPosition());

    //     if(towardsColony == false) 
    //     {
    //         m_body.setRotation(angleToColony);
    //         towardsColony = true;
    //     }
    
    //     m_direction.x = sin(degToRad(m_body.getRotation()));
    //     m_direction.y = -cos(degToRad(m_body.getRotation()));
    // }

        m_body.move(m_direction.x * deltaTime, m_direction.y * deltaTime);
    
}
