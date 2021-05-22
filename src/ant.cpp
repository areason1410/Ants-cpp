#include "ant.hpp"
#include <iostream>
// #include "utils.hpp"

float degToRad(float angle)
{
    float pi = 3.14159265359;
    return angle * (pi / 180);
    
}

int ranged_rand(int min, int max) {
    return min + (int)((double)(max - min) * (rand() / (RAND_MAX + 1.0)));
}


Ant::Ant(sf::Vector2f size, sf::Vector2f colonyCenter):
    size(size),
    colonyCenter(colonyCenter)
    {
        antBody.setSize(size);
        antBody.setOrigin(size.x/2, size.y/2);
        antBody.setPosition(colonyCenter);
        antBody.setFillColor(sf::Color::Red);
        antBody.setRotation(rand() % 360);
        direction.x = sin(degToRad(antBody.getRotation()));
        direction.y = -cos(degToRad(antBody.getRotation()));
        foodBody.setRadius(3);
        foodBody.setFillColor(sf::Color::Green);
    }

void Ant::move(bool moveState)
{
    float deltaTime = dt.restart().asSeconds() * 100;
    if(moveState)
    {
        antBody.setRotation(antBody.getRotation() + ranged_rand(-4, 5));
        direction.x = sin(degToRad(antBody.getRotation()));
        direction.y = -cos(degToRad(antBody.getRotation()));
        antBody.move(direction.x * deltaTime, direction.y * deltaTime);
    }

    
}

void Ant::turnAround() {antBody.setRotation(antBody.getRotation() + 180);}


void Ant::stateManager(sf::RenderWindow &window, sf::CircleShape colonyBody)
{
    if((int)antBody.getPosition().x <= 10) 
    {
        antBody.setPosition(sf::Vector2f(antBody.getPosition().x + 10, antBody.getPosition().y));
        turnAround();
    }
    if((int)antBody.getPosition().x >= window.getSize().x - 10)
    {
        antBody.setPosition(sf::Vector2f(antBody.getPosition().x - 10, antBody.getPosition().y));
        turnAround();
    }
    if((int)antBody.getPosition().y <= 10)
    {
        antBody.setPosition(sf::Vector2f(antBody.getPosition().x, antBody.getPosition().y + 10));
        turnAround();
    };
    if((int)antBody.getPosition().y >= window.getSize().y - 10)
    {
        antBody.setPosition(sf::Vector2f(antBody.getPosition().x, antBody.getPosition().y - 10));
        turnAround();
    }

    if(state == true)
    {
        foodBody.setPosition(antBody.getPosition());
        window.draw(foodBody);
        if(antBody.getGlobalBounds().intersects(colonyBody.getGlobalBounds()))
        {
            state = false;
            turnAround();
        }
    }
}