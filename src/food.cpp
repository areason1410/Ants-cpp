#include "food.hpp"

Food::Food(sf::Vector2f pos, sf::Vector2f size):
    pos(pos),
    size(size)
    {
        foodBody.setPosition(pos);
        foodBody.setSize(sf::Vector2f(size.x,size.y));
        foodBody.setFillColor(sf::Color(0, 255, 0, 255));
        // hitbox.setSize(sf::Vector2f(30,30));
        // hitbox.setPosition(foodBody.getPosition().x - 8, foodBody.getPosition().y -8);
    }