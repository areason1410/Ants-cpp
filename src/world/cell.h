#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum TrailType
{
    Home,
    Food
};


class Cell
{
public:
    Cell(float size_x, float size_y, int a, int b, int index);
    int m_xPos, m_yPos;
    void addFood();
    void makeHomeTrail();
    void makeFoodTrail();
    sf::Vector2f Size() const;
    sf::Vector2f Pos() const;
    void draw(sf::RenderWindow &window, bool shouldDrawTrail);
    void update();
    //bool hasFood() const;
    
    bool m_hasFood = false;
    bool m_isTrail = false;
    TrailType m_trailType;
    int m_index;
    int m_trailIntensity = m_maxTrailIntensity;
    
private:
    sf::RectangleShape rect;
    float m_sizeX, m_sizeY;
    int m_foodHP = 100;
    int m_maxTrailIntensity = 150;
    bool m_shouldDraw = false;
};