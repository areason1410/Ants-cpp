#include "cell.h"




Cell::Cell(float size_x, float size_y, int a, int b, int index):
m_sizeX(size_x),
m_sizeY(size_y),
m_xPos(a),
m_yPos(b),
m_index(index)
{
    m_hasFood = false;
    rect.setSize(sf::Vector2f(m_sizeX, m_sizeY));
    rect.setPosition(m_xPos, m_yPos);
    rect.setFillColor(sf::Color(255, 255, 255, 0));
    
}

sf::Vector2f Cell::Size() const
{
    return sf::Vector2f(m_sizeX, m_sizeY);
}


sf::Vector2f Cell::Pos() const
{
    return sf::Vector2f(m_xPos, m_yPos);
}

void Cell::draw(sf::RenderWindow &window, bool shouldDrawTrail)
{
    if(m_trailIntensity > 0) { m_trailIntensity -= 2; }
    else { m_isTrail = false; }

    if(!m_hasFood && !shouldDrawTrail) { return; }


    //very ugly i want to change but it works for now
    if(m_isTrail == true)
    {
        if(m_trailType == TrailType::Home)
        {
            rect.setFillColor(sf::Color(255, 0, 0, m_trailIntensity));
        } 
        else if(m_trailType == TrailType::Food)
        {
            rect.setFillColor(sf::Color(0, 0, 255, m_trailIntensity));
        }
        m_shouldDraw = true;

    }
    else if(m_hasFood == true)
    {
        rect.setFillColor(sf::Color(0, 255, 0, m_foodHP));
        m_shouldDraw = true;
    }
    else if(m_shouldDraw) { m_shouldDraw = false; }

    if(!m_shouldDraw) return;
    window.draw(rect);
}

void Cell::addFood()
{
    m_hasFood = true;
}

void Cell::makeHomeTrail()
{
    if(m_trailType == TrailType::Food) return;
    if(!m_hasFood) m_isTrail = true;
    m_trailIntensity = m_maxTrailIntensity;
}

void Cell::makeFoodTrail()
{
    if(!m_hasFood) m_isTrail = true;
    m_trailIntensity = m_maxTrailIntensity;
}

void Cell::update()
{
    
}
