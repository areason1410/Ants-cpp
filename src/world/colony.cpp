#include "colony.h"


Colony::Colony(int antCount):
m_antCount(antCount)
{
    m_colonyBody.setPosition(960, 540);
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

        a.onRotationCooldown = 1 - a.waitTimer.update(dt*10);
        //std::cout << a.onRotationCooldown << "\n";

        Cell* currentCell = grid.getCellAt(a.m_body.getPosition());
        if(currentCell->m_hasFood)
        {
            a.carryingFood = true;
        }
        else
        {
            if(a.carryingFood)
            {
                currentCell->m_trailType = TrailType::Food;
                currentCell->makeFoodTrail();
            } 
            else
            {
                Cell* bestOption = grid.sample(currentCell->m_index, a.m_searchRadius, TrailType::Food);  
                if(bestOption->m_index != -1)
                {
                    int angle = angleAB(bestOption->Pos(), a.m_body.getPosition());
                    
                    if(a.onRotationCooldown == false) 
                    {
                        std::cout << angle << "\n";
                        a.m_body.setRotation(angle);
                    }
                }
                currentCell->makeHomeTrail();

                }
        }
        //std::cout << t->m_index << "\n";
        a.move(dt, window.getSize());
        window.draw(a.m_body);

    }

}