
#pragma once
#include <math.h>
#include <SFML/Graphics.hpp>
#include "../world/cell.h"

static float degToRad(float angle)
{
    float pi = 3.14159265359;
    return angle * (pi / 180);
    
}

static float radToDeg(float angle)
{
    float pi = 3.14159265359;
    return angle * (180 / pi);
}
template<typename T>
static float getLength(sf::Vector2<T> v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

static float angleAB(sf::Vector2f a, sf::Vector2f b)
{

        float distX = a.x - b.x;
        float distY = a.y - b.y;

        float angle = 270 - radToDeg(atan2(distY, distX));
        return -angle;

        //float angle = 90+radToDeg(atan2(distY, distX));
        //float angle = 90 + radToDeg(acos(distX / (getLength(a-b))));
        //return angle;
        //return distY > 0.0f ? angle : -angle;
}

template<typename T>
static int ranged_rand(T min, T max) {
    return min + (int)((double)(max - min) * (rand() / (RAND_MAX + 1.0)));
}



static float getAngle(const sf::Vector2f & v)
{
	const float a = acos(v.x / getLength(v));
	return v.y > 0.0f ? a : -a;
}

struct Wait
{
    float m_duration;
    float m_currentDuration = 0;

    Wait(float time): m_duration(time) {};

    void reset() { m_currentDuration = 0; }

    bool update(float dt)
    {
        m_currentDuration += dt;

        if(m_currentDuration >= m_duration)
        {
            this->reset();
            return true;
        }
        return false;
    }

};

enum DirectionType
{
    Above,
    Below,
    Left,
    Right
};

