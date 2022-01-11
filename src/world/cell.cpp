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

void Cell::draw(sf::RenderWindow &window)
{

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

        if(m_trailIntensity > 0) m_trailIntensity -= 2;
        else m_isTrail = false;

    }
    if(m_hasFood == true)
    {
        rect.setFillColor(sf::Color(0, 255, 0, m_foodHP));
    }

    
    window.draw(rect);
}

void Cell::addFood()
{
    m_hasFood = true;
}

void Cell::makeTrail()
{
    m_isTrail = true;
    m_trailIntensity = m_maxTrailIntensity;
}

void Cell::update()
{
    
}

// bool Cell::hasFood() const
// {
//     return m_hasFood;
// }