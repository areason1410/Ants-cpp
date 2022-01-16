#include "windowManager.h"

WindowManager::WindowManager(sf::RenderWindow& window, World world):
m_renderWindow(window),
m_world(world)
{

}


void WindowManager::zoom(float zf) 
{
    m_zoom *= zf;

}


void WindowManager::processEvents()
{
    sf::RectangleShape background;
    background.setFillColor(sf::Color(sf::Color(45, 30, 23)));
    background.setSize((sf::Vector2f)m_renderWindow.getSize());
    m_renderWindow.draw(background);

    m_fps.update();
    std::string s = std::to_string(m_fps.getFPS());
    m_renderWindow.setTitle(s); 
    m_world.update(m_renderWindow);

    sf::View view = m_renderWindow.getDefaultView();

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
                if(event.key.code == sf::Keyboard::T) m_world.toggleTrails();
                break;
            case sf::Event::MouseWheelMoved:
                this->zoom(1 - event.mouseWheel.delta * 0.2f);
                view.setSize(m_renderWindow.getDefaultView().getSize());
                view.zoom(m_zoom);
                m_renderWindow.setView(view);
                break;
            case sf::Event::MouseButtonPressed:
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    //moving = true;
                    

                }
                break;
            case sf::Event::MouseButtonReleased:
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    //moving = false;
                }
            break;
            case sf::Event::MouseMoved:
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
        m_renderWindow.clear(sf::Color(25, 10, 3));
}