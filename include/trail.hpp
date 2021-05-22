#include <SFML/Graphics.hpp>

class Trail
{
public:
    Trail(sf::Vector2f pos, sf::Vector2f size, bool type, float rotation);

    void updateIntensity();
    void draw();

    sf::RectangleShape body;
    sf::RectangleShape toHome, toFood;
    float intensity = 255;
    bool type;
    float rotation;
private:
    sf::Vector2f pos, size;
};