
#pragma once
#include <math.h>
#include <SFML/Graphics.hpp>

static float degToRad(float angle)
{
    float pi = 3.14159265359;
    return angle * (pi / 180);
    
}

template<typename T>
static int ranged_rand(T min, T max) {
    return min + (int)((double)(max - min) * (rand() / (RAND_MAX + 1.0)));
}

template<typename T>
static float getLength(sf::Vector2<T> v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}
