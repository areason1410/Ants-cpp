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

        Cell* currentCell = grid.getCellAt(sf::Vector2f(a.m_body.getPosition().x, a.m_body.getPosition().y));
        currentCell->makeTrail();
        if(currentCell->m_hasFood)
        {
            a.carryingFood = true;
        }
        else
        {
            if(a.carryingFood)
            {
                //currentCell->m_trailType = TrailType::Food;
            } 
            else
            {
                int bestOption = grid.sample(currentCell->m_index, 3);  

                //std::cout << bestOption << "\n";
                //int angle = angleAB(sf::Vector2f(grid.m_cells[bestOption].m_xPos, grid.m_cells[bestOption].m_yPos), a.m_body.getPosition());
                //if(!a.onRotationCooldown) a.m_body.setRotation(-angle);
            }
        }
        //std::cout << t->m_index << "\n";
        

    }

}