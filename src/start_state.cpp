
#include "start_state.hpp"

start_state::start_state(head& h):
    player {h}
    {
   
    }

void start_state::handle_events(const sf::Event& e) 
{
    switch(e.key.code)
    {
    case sf::Keyboard::Space:
        change_state("game");
        break;
    
    default:
        break;
    }
}

void start_state::update()
{

}

void start_state::draw(sf::RenderWindow& w)
{
    player.draw(w);
}

void start_state::cleanup()
{
    
}

void start_state::startup()
{
    player.update();
}