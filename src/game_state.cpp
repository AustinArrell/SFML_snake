
#include "game_state.hpp"

game_state::game_state(head& h):
    player {h}
    {
   
    }

void game_state::handle_events(const sf::Event& e) 
{
    switch(e.key.code)
    {
    case sf::Keyboard::Left:
        if(player.get_dir() != direction::RIGHT)
            player.set_dir(direction::LEFT);
        break;

    case sf::Keyboard::Right:
        if(player.get_dir() != direction::LEFT)
            player.set_dir(direction::RIGHT);
        break;

    case sf::Keyboard::Up:
        if(player.get_dir() != direction::DOWN)
            player.set_dir(direction::UP);
        break;

    case sf::Keyboard::Down:
        if(player.get_dir() != direction::UP) 
            player.set_dir(direction::DOWN);
        break;
    
    default:
        break;
    }
}

void game_state::update()
{
    player.update();
}

void game_state::draw(sf::RenderWindow& w)
{
    player.draw(w);
}

void game_state::cleanup()
{

}

void game_state::startup()
{

}