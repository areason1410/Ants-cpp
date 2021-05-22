#include <SFML/Graphics.hpp>

class Food
{
public:
    Food(sf::Vector2f pos, sf::Vector2f size);
    void drawBody();
    sf::RectangleShape foodBody;
    int foodCount = 100;
    sf::RectangleShape hitbox;
private:
    sf::Vector2f pos, size;
};