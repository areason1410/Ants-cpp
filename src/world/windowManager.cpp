#include "windowManager.h"

WindowManager::WindowManager(sf::RenderWindow& window, World world):
m_renderWindow(window),
m_world(world)
{

}

void WindowManager::processEvents()
{
    m_fps.update();
    std::string s = std::to_string(m_fps.getFPS());
    m_renderWindow.setTitle(s); 
    m_world.update(m_renderWindow);
    sf::Event event;
        while (m_renderWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_renderWindow.close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape) m_renderWindow.close();
                if(event.key.code == sf::Keyboard::G);
                break;
            default:
                break;
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_world.addFoodAt(sf::Vector2f(sf::Mouse::getPosition(m_renderWindow)));
        }

        //grid.lol();
        m_renderWindow.display();
        m_renderWindow.clear(sf::Color(45, 30, 23));
}