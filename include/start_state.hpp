
#pragma once

#include "state_manager.hpp"
#include "head.hpp"

class start_state : public state
{
    void handle_events(const sf::Event& e) override;

    void update() override;

    void draw(sf::RenderWindow& w) override;
    
    void cleanup() override;
    
    void startup() override;

    head& player;

    sf::Font font;

    sf::Text high_score_text;
    sf::Text start_text;
    sf::Text start_sub_text;

public:
    start_state(head& h);
};
