
#include "game_state.hpp"
#include <filesystem>
#include <iostream>


game_state::game_state(head& h, int& s):
    player {h},
    score {s}
    {
        font.loadFromFile("../fonts/PressStart2P.ttf");
        score_text.setFont(font);
        score_text.setString("Score:" + std::to_string(score));
        score_text.setCharacterSize(18);
        score_text.setFillColor(sf::Color::White);
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
    food.update();

    //Check if the apple and the head are touching
    if (player.get_sprite().getGlobalBounds().intersects(food.get_sprite().getGlobalBounds()))
    {
        food.move();
        player.generate_segment();
        score += 10;
        score_text.setString("Score:" + std::to_string(score));
    }

    while (!player.validate_location(food.get_sprite()))
    {
        food.move();
    }

    if (player.check_collisions())
    {
        change_state("end");
    }
}

void game_state::draw(sf::RenderWindow& w)
{
    food.draw(w);
    player.draw(w);
    w.draw(score_text);
    
}

void game_state::cleanup()
{

}

void game_state::startup()
{
    score = 0;
}

int game_state::get_score()
{
    return score;
}