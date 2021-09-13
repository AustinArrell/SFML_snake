
#include "end_state.hpp"

end_state::end_state(head& h):
    player {h}
    {
   
    }

void end_state::handle_events(const sf::Event& e) 
{
    switch(e.key.code)
    {
    case sf::Keyboard::Space:
        change_state("start");
        break;
    
    default:
        break;
    }
}

void end_state::update()
{

}

void end_state::draw(sf::RenderWindow& w)
{
    player.draw(w);
}

void end_state::cleanup()
{
    player.set_pos(window_width/tile_size/2, window_height/tile_size/2);
    player.clear_stack();
}

void end_state::startup()
{

}