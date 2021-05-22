#include <SFML/Graphics.hpp>
#include <string>
#include "world.hpp"

int main()
{

        srand (time(NULL));

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Ants", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    Colony colony(window, 360);
    World gameWorld(window, colony);
    
    while (window.isOpen())
    {    
        gameWorld.processEvents();
    }

    return 0;
}

