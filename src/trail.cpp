#include "trail.hpp"

Trail::Trail(sf::Vector2f pos, sf::Vector2f size, bool type, float rotation):
    pos(pos),
    size(size),
    type(type),
    rotation(rotation)
    {
        body.setSize(size);
        body.setPosition(pos);

        if(type == 0)
        {
            
            body.setFillColor(sf::Color(255, 0, 0, 255));
            toHome.setSize(sf::Vector2f(15,15));
            toHome.setPosition(pos);
        }
        else
        {
            body.setFillColor(sf::Color(0, 255, 0, 255));
            toFood.setSize(sf::Vector2f(15,15));
            toFood.setPosition(pos);
        }
    }

void Trail::updateIntensity()
{
    if(intensity > 0) intensity -= 1;
    else intensity = 0;
    if(type == false) body.setFillColor(sf::Color(255, 0, 0, intensity));
    else body.setFillColor(sf::Color(0, 255, 0, intensity));
}