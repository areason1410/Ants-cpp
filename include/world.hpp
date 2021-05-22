#include <SFML/Graphics.hpp>
#include "time.h"
#include "colony.hpp"
#include "trail.hpp"
#include <food.hpp>

class World : public sf::RenderWindow
{
public:
    World(sf::RenderWindow &window, Colony &colony);

    void drawAll();
    void processEvents();
    void renderTrails(bool renderState);
    void drawGrid();
    void drawTrails();
    void checkAnt();
    void addFoodAt(sf::Vector2f pos);
    void damageFood(sf::Vector2f pos);
    void makeTrail(sf::Vector2f pos, sf::Vector2f size, float rotation);
    void makeFoodTrail(sf::Vector2f pos, sf::Vector2f size, float rotation);

    int getTrailAt(sf::Vector2f pos);
    int checkIfGridIsEmpty(sf::Vector2f gridNumber);

    sf::Vector2f getGridPos(sf::Vector2f pos);
    sf::Vector2f getGridNumberAt(sf::Vector2f pos);
    std::vector<Food> food;
    std::vector<Trail> trails;
    std::vector<std::vector<int>> gridSpace;


private:
    float ratio;

    sf::Vector2f gridPos,
                 gridSize;
    sf::RenderWindow &window;
    sf::Clock clock;
    bool drawGridsState = false,
         drawTrailsState = false,
         drawAntsState = true,
         playState = false;
    FPS fps;
    Colony &colony;
};