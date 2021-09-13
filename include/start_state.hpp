
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

public:
    start_state(head& h);
};