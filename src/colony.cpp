#include <colony.hpp>

Colony::Colony( sf::RenderWindow &window, int antCount):
    window(window),
    antCount(antCount)
    {
        colonyBody.setPosition(window.getSize().x / 2 , window.getSize().y / 2);
        colonyBody.setRadius(50);
        colonyBody.setOrigin(colonyBody.getRadius()/2, colonyBody.getRadius()/2);
        colonyBody.setFillColor(sf::Color::White);
        
        for(int i = 0; i < antCount; i++)
        {
            // was 2,5
            Ant ant(sf::Vector2f(1,3), colonyBody.getPosition() + colonyBody.getOrigin());
            ants.push_back(ant);
        }
    }

void Colony::render()
{
    window.draw(colonyBody);
}


void Colony::renderAnts(FPS fps, bool renderState, bool playState)
{
    float t = time.getElapsedTime().asSeconds();
    float f = 10 / (float)fps.getFPS();
    for(int i = 0; i < antCount; i++)
    {
        manageAnts(i, playState);
        if(renderState) window.draw(ants[i].antBody);
    }
    if(t > f) time.restart();
}

void Colony::manageAnts(int i, bool playState)
{
    ants[i].stateManager(window, colonyBody);
    ants[i].move(playState);
    
}

// void Colony::manageTrails(int i)
// {


//     Trail trail(ants[i].antBody.getPosition(), ants[i].state);
//     if(ants[i].state == false)
//     {
//         trail.toHome.setRotation(ants[i].antBody.getRotation() + 180);
//         // trail.foodToHome.setRotation(ants[i].antBody.getRotation() + 180);

//         trails.push_back(trail);
//     }
//     else
//     {
//         trail.toFood.setRotation(ants[i].antBody.getRotation() + 180);
//         trails.push_back(trail);
//     }

//     ants[i].trail.push_back(trail);
// }
