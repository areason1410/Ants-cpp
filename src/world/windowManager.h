#pragma once
#include <SFML/Graphics.hpp>
#include "world.h"
#include "../util/fps.h"

class WindowManager
{
public:
    WindowManager(sf::RenderWindow& window, World world);
    void processEvents();


    sf::RenderWindow& m_renderWindow;
    FPS m_fps;
    World m_world;

};