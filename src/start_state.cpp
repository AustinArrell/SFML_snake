
#include "start_state.hpp"

start_state::start_state(head& h):
    player {h}
    {
        font.loadFromFile("../fonts/PressStart2P.ttf");
        high_score_text.setFont(font);
        high_score_text.setFillColor(sf::Color::White);

        start_text = high_score_text;
        start_sub_text = high_score_text;

        high_score_text.setString("High Score:" + std::to_string(0));
        high_score_text.setCharacterSize(18);

        start_text.setString("Welcome to Snake!");
        start_text.setCharacterSize(32);
        start_text.setPosition( (window_width/2)-(start_text.getLocalBounds().width/2), (window_height/2) - (start_text.getLocalBounds().height/2));

        start_sub_text.setString("Press spacebar to begin.");
        start_sub_text.setCharacterSize(12);
        start_sub_text.setPosition((window_width/2)-(start_sub_text.getLocalBounds().width/2), (window_height/2) + 32);
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
    w.draw(start_text);
    w.draw(start_sub_text);
    w.draw(high_score_text);
}

void start_state::cleanup()
{
    
}

void start_state::startup()
{

}