#include "FPSCounter.h"

#include "../Renderer/RenderMaster.h"

#include <iostream>

FPSCounter::FPSCounter()
{
    enabled = true;
    debugging = false;

    // m_text.setPosition(sf::Vector2f(10.f,10.f));
    m_text.move(10, 10);
    m_text.setOutlineColor(sf::Color::Black);
    m_text.setOutlineThickness(2);
    // TODO: it is better to use some kind of embedder like in qresources.
    // e.g.: https://github.com/raysan5/rres
    m_font.loadFromFile("Res/Fonts/rs.ttf");
    m_text.setFont(m_font);
    m_text.setCharacterSize(25);
}

void FPSCounter::update()
{
    m_frameCount++;

    if(enabled)
    {
        if (m_delayTimer.getElapsedTime().asSeconds() > 0.5)
        {
            m_fps = m_frameCount / m_fpsTimer.restart().asSeconds();
            m_frameCount = 0;
            m_delayTimer.restart();
        
            // Only show this output in debug mode
            if(debugging)
            {
                std::cout << m_fps << '\n';
            }
        }
    }
}

void FPSCounter::draw(RenderMaster &renderer)
{
    m_text.setString("FPS: " + std::to_string(m_fps));
}
