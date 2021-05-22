#include <SFML/Graphics.hpp>
#include <math.h>

class Ant
{
public:

    bool state = false;

    Ant(sf::Vector2f size, sf::Vector2f colonyCenter);
    sf::RectangleShape antBody;
    void move(bool moveState);
    void turnAround();
    void stateManager(sf::RenderWindow &window, sf::CircleShape colonyBody);
    sf::Clock dt;
    sf::CircleShape foodBody;
    
private:
    sf::Vector2f size, colonyCenter, direction, velocity;
};