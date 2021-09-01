#include <SFML/Graphics.hpp>
#include "head.hpp"
#include "keyboard.hpp"
#include <iostream>
#include "globals.hpp"

// TODO: CMAKE

int main()
{
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "SNEK");

    head player;
    
    // Setup 2D Vector and init as all 0s
    std::vector<std::vector<int>> game_board;
    game_board.resize(40);
    for (auto& element : game_board)
    {
        element.resize(30, 0);
    }

    sf::Clock clock;
    sf::Int64 frame_time;
    sf::Int64 time_per_update = (sf::Int64)(1e6/8.0);
    sf::Int64 cumulative_time = 0;

    while (window.isOpen())
    {
        sf::Event event;

        frame_time = clock.restart().asMicroseconds();
        cumulative_time += frame_time;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            
            case sf::Event::Closed:
                window.close();
                break;
            
            case sf::Event::KeyPressed:
                handle_input(event, player);
                break;
            
            default:
                break;
                
            }
        }

        if (cumulative_time >= time_per_update) 
        {
            player.update();
            cumulative_time -= time_per_update;
        }
        
        window.clear();
        player.draw(window);
        window.display();
        
    }

    return 0;
}