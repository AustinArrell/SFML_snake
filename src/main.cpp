
#include <SFML/Graphics.hpp>
#include "head.hpp"
#include <iostream>
#include "globals.hpp"
#include "state_manager.hpp"
#include "start_state.hpp"
#include "game_state.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "SNEK");
    
    head player;
    
    start_state start_state(player);
    game_state game_state(player);

    add_state("start",start_state);
    add_state("game",game_state);
    change_state("start");

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
                handle_events(event);
                break;
            
            default:
                break;
                
            }
        }

        if (cumulative_time >= time_per_update) 
        {
            update_state();
            cumulative_time -= time_per_update;
        }
        
        window.clear();
        render_state(window);
        window.display();
        
    }

    return 0;
}