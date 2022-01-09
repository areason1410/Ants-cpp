#include <SFML/Graphics.hpp>
#include <string>
#include "world/windowManager.h"


int main()
{

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Ants", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    srand (time(NULL));
    Grid grid(window);
    World gameWorld(grid);
    WindowManager windowManager(window, gameWorld);
    
    while (window.isOpen())
    {    
        windowManager.processEvents();
    }

    return 0;
}

