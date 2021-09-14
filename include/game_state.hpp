
#pragma once

#include "state_manager.hpp"
#include "head.hpp"
#include "apple.hpp"

class game_state : public state
{
    void handle_events(const sf::Event& e) override;

    void update() override;

    void draw(sf::RenderWindow& w) override;

    void cleanup() override;
    
    void startup() override;

    head& player;

    apple food;

    sf::Font font;

    int& score;

    sf::Text score_text;

public:
    game_state(head& h, int& s);

    int get_score();
};
