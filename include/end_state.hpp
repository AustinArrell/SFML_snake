
#pragma once

#include "state_manager.hpp"
#include "head.hpp"

class end_state : public state
{
    void handle_events(const sf::Event& e) override;

    void update() override;

    void draw(sf::RenderWindow& w) override;
    
    void cleanup() override;
    
    void startup() override;

    head& player;

    sf::Font font;

    int& score;

    sf::Text score_text;
    sf::Text game_over_text;
    sf::Text game_over_sub_text;

public:
    end_state(head& h, int& s);
};
