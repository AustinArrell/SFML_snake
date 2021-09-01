#include "keyboard.hpp"
#include <SFML/Graphics.hpp>
#include "head.hpp"
#include "globals.hpp"

void handle_input(const sf::Event& e, head& s)
{
    switch (e.key.code) 
    {

    case sf::Keyboard::Left:
        if(s.get_dir() != direction::RIGHT)
            s.set_dir(direction::LEFT);
        break;

    case sf::Keyboard::Right:
        if(s.get_dir() != direction::LEFT)
            s.set_dir(direction::RIGHT);
        break;

    case sf::Keyboard::Up:
        if(s.get_dir() != direction::DOWN)
            s.set_dir(direction::UP);
        break;

    case sf::Keyboard::Down:
        if(s.get_dir() != direction::UP) 
            s.set_dir(direction::DOWN);
        break;

    default:
        break;
    } 

}