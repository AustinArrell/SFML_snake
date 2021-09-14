
#include "end_state.hpp"
#include "number_gen.hpp"

end_state::end_state(head& h, int& s):
    player {h},
    score {s}
    {
        font.loadFromFile("../fonts/PressStart2P.ttf");
        score_text.setFont(font);
        score_text.setFillColor(sf::Color::White);

        game_over_text = score_text;
        game_over_sub_text = score_text;

        score_text.setString("Score:" + std::to_string(score));
        score_text.setCharacterSize(18);

        game_over_text.setString("Game Over");
        game_over_text.setCharacterSize(32);
        game_over_text.setPosition( (window_width/2)-(game_over_text.getLocalBounds().width/2), (window_height/2) - (game_over_text.getLocalBounds().height/2));
        

        game_over_sub_text.setString("Press spacebar to try again.");
        game_over_sub_text.setCharacterSize(12);
        game_over_sub_text.setPosition( (window_width/2)-20-(game_over_text.getLocalBounds().width/2), (window_height/2) + 32);
        

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
    w.draw(score_text);
    w.draw(game_over_text);
    w.draw(game_over_sub_text);
}

void end_state::cleanup()
{
    player.set_pos(window_width/tile_size/2, window_height/tile_size/2);
    player.set_dir(static_cast<direction>((rand_range(0,3))));
    player.clear_stack();
}

void end_state::startup()
{
    score_text.setString("Score:" + std::to_string(score));
}