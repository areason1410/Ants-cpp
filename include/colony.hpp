#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "ant.hpp"
#include "fps.hpp"

class Colony
{
public:
    Colony( sf::RenderWindow &window, int antCount);
    sf::CircleShape colonyBody;
    void render();

    void renderAnts(FPS fps, bool renderState, bool playState);
    void manageAnts(int i, bool playState);
    void manageTrails(int i);

    std::vector<Ant> ants;
    int antCount;
private:
    sf::RenderWindow &window;
    float x, y;
    sf::Clock time;
};