#include "colony.h"


Colony::Colony(int antCount):
m_antCount(antCount)
{
    m_colonyBody.setPosition(500, 200);
    m_colonyBody.setRadius(25);
    m_colonyBody.setOrigin(m_colonyBody.getRadius()/2, m_colonyBody.getRadius()/2);
    m_colonyBody.setFillColor(sf::Color(181, 75, 30));

    for(int i = 0; i < m_antCount; i++)
    {
        Ant ant(m_colonyBody.getPosition() + m_colonyBody.getOrigin());
        ants.push_back(ant);
    }
}

void Colony::update(Grid& grid, sf::RenderWindow& window)
{
    window.draw(m_colonyBody);
    dt = m_clock.restart().asSeconds();
    for (Ant& a : ants) 
    {
        a.move(dt, window.getSize());
        window.draw(a.m_body);

        Cell* t = grid.getCellAt(sf::Vector2f(a.m_body.getPosition().x, a.m_body.getPosition().y));
        if(t->m_hasFood)
        {
            a.carryingFood = true;
        }
        t->makeTrail();
    

    }

}