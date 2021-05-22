#include "world.hpp"
#include <iostream>


float checkRotation(float antRotation)
{
    float rotation;
    if(antRotation < 180) rotation = antRotation + 180;
    else rotation = antRotation - 180;
    return rotation;
}

World::World(sf::RenderWindow &window, Colony &colony):
    window(window),
    colony(colony)
    {
        ratio = (float)window.getSize().y / (float)window.getSize().x;
        sf::Clock clock;

        gridSize.y = 100;
        gridSize.x = gridSize.y / ratio;
        gridPos.x = window.getSize().x / gridSize.x;
        gridPos.y = window.getSize().y / gridSize.y;
        for(int i = 0; i < gridSize.x + 5; i++)
        {
            std::vector<int> jv;
            for(int j = 0; j < gridSize.y + 5; j++)
            {
                jv.push_back(0);
            }
            gridSpace.push_back(jv);
        }
    }

void World::processEvents()
{

    fps.update();
    std::string s = std::to_string(fps.getFPS());
    window.setTitle(s); 
    sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape) window.close();
                if(event.key.code == sf::Keyboard::M) drawTrailsState ^= true;
                if(event.key.code == sf::Keyboard::G) drawGridsState ^= true;
                if(event.key.code == sf::Keyboard::A) drawAntsState ^= true;
                if(event.key.code == sf::Keyboard::P) playState ^= true;
                break;
            default:
                break;
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            addFoodAt(getGridPos(sf::Vector2f(sf::Mouse::getPosition(window))));
        }
        if(drawGridsState) drawGrid();
        checkAnt();
        drawAll();
        window.display();
        window.clear();
}

void World::drawAll()
{  
    colony.render();
    colony.renderAnts(fps, drawAntsState, playState);
    for(int i = 0; i < food.size(); i++)
    {
        window.draw(food[i].foodBody);
    }
    for(int i = 0; i < trails.size(); i++)
    {
        if(drawTrailsState == true) window.draw(trails[i].body);

        //this makes it massively crash...
        // trails[i].updateIntensity();
        // if(trails[i].intensity <= 40)
        // {
        //     sf::Vector2f loc = getGridNumberAt(trails[i].body.getPosition());
        //     trails.erase(trails.begin() + i);
        //     gridSpace[loc.x][loc.y] = 0;
        // } 
    }
    // std::cout << trails.size() << "\n";
}

void World::drawGrid()
{

    // std::cout << getGridPos(sf::Vector2f(40,10)).x << "\n";

    for(int i = 0; i < gridSize.x; i++)
    {
        for(int j = 0; j < gridSize.y; j++)
        {
            sf::RectangleShape f;
            f.setPosition(sf::Vector2f(gridPos.x * i, gridPos.y * j));
            f.setSize(sf::Vector2f(gridPos.x, 1));
            f.setFillColor(sf::Color(160, 32, 240, i));
            window.draw(f);

        }
    }
    for(int i = 0; i < gridSize.y*2; i++)
    {
        for(int j = 0; j < gridSize.x; j++)
        {
            sf::RectangleShape f;
            f.setRotation(90);
            f.setSize(sf::Vector2f(gridPos.x, 1));
            f.setFillColor(sf::Color(160, 32, 240, i));
            f.setPosition(sf::Vector2f(gridPos.y * i, gridPos.x * j));
            window.draw(f);

        }
    }

}

void World::checkAnt()
{
    for(int i = 0; i < colony.antCount; i++)
    {
        sf::RectangleShape f;
        f.setSize(sf::Vector2f(gridPos.x, gridPos.y));
        f.setPosition(getGridPos(colony.ants[i].antBody.getPosition()));
        if(colony.ants[i].state == false)
        {
            if(checkIfGridIsEmpty(getGridNumberAt(f.getPosition())) == 1) //1 = food, 2 = redtrail, 3 = greentrail
            {
                colony.ants[i].state = true;
                colony.ants[i].turnAround();
                damageFood(getGridNumberAt(f.getPosition()));
            }
            else if( checkIfGridIsEmpty(getGridNumberAt(f.getPosition())) == 3)
            {
                // float index = getTrailAt(f.getPosition());
                // colony.ants[i].antBody.setRotation(trails[index].rotation);
                // std::cout << trails[index].rotation << "\n";
            }
            else
            {
                float rotation = checkRotation(colony.ants[i].antBody.getRotation());
                makeTrail(f.getPosition(), f.getSize(), rotation);

            }

        }
        else
        {
            float rotation = checkRotation(colony.ants[i].antBody.getRotation());
            // makeFoodTrail(f.getPosition(), f.getSize(), rotation); very laggy rn
        }
    }
}

void World::makeTrail(sf::Vector2f pos, sf::Vector2f size, float rotation)
{
    // std::cout << "bam\n";
    size.x = size.x / 2;
    size.y = size.y / 2;
    sf::Vector2f gridNum = getGridNumberAt(pos);
    if(checkIfGridIsEmpty(gridNum) == 0)
    {
        Trail tr(pos, size, 0, rotation);
        gridSpace[gridNum.x][gridNum.y] = 2;
        trails.push_back(tr);
    }
}

void World::makeFoodTrail(sf::Vector2f pos, sf::Vector2f size, float rotation)
{
    // std::cout << "bam\n";
    size.x = size.x / 2;
    size.y = size.y / 2;
    sf::Vector2f gridNum = getGridNumberAt(pos);
    if( checkIfGridIsEmpty(gridNum) == 0|| checkIfGridIsEmpty(gridNum) == 2)
    {
        Trail tr(pos, size, 1, rotation);
        gridSpace[gridNum.x][gridNum.y] = 3;
        int index = getTrailAt(pos);
        if(index != -1) trails.erase(trails.begin() + index);
        trails.push_back(tr);
    }
}

int World::getTrailAt(sf::Vector2f pos)
{
    for(int i = 0; i < trails.size(); i++)
    {
        if(trails[i].body.getPosition() == pos) return i;
    }
    return -1;
}

void World::damageFood(sf::Vector2f pos)
{
    for(int i = 0; i < food.size(); i++)
    {
        sf::Vector2f loc = getGridNumberAt(food[i].foodBody.getPosition());
        if(pos.x == loc.x && pos.y == loc.y)
        {
            food[i].foodCount--;
            food[i].foodBody.setFillColor(sf::Color(0, 255, 0, 150));
            if(food[i].foodCount <= 0)
            {
                food.erase(food.begin() + i);
                gridSpace[loc.x][loc.y] = 0;
            }
        }
    }
}

sf::Vector2f World::getGridPos(sf::Vector2f pos)
{
    float cellX = floor(pos.x / gridPos.x);
    float cellY = floor(pos.y / gridPos.y);

    return sf::Vector2f(cellX * gridPos.x, cellY * gridPos.y);
}

sf::Vector2f World::getGridNumberAt(sf::Vector2f pos)
{
    return sf::Vector2f(pos.x / gridPos.x, pos.y / gridPos.y);
}

int World::checkIfGridIsEmpty(sf::Vector2f gridNumber)
{
    switch (gridSpace[gridNumber.x][gridNumber.y])
    {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    default:
        return 0;
        break;
    }
}

void World::addFoodAt(sf::Vector2f pos)
{
    bool state = false;
    for(int i = 0; i < food.size(); i++)
    {
         if(checkIfGridIsEmpty(getGridNumberAt(pos)) == 1)
         {
             food[i].foodCount += 100;
             state = true;
         }
    }
    if(!state) 
    {
        sf::Vector2f xy = getGridNumberAt(pos);
        Food f(pos, gridPos);
        food.push_back(f);
        gridSpace[xy.x][xy.y] = 1;
    }
}
