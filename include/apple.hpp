
#pragma once

#include <SFML/Graphics.hpp>
#include <random>

class apple
{
    sf::Vector2i pos = {5,5};

    sf::RectangleShape sprite;

public:
    apple();

    void move();

    void update();

    void draw(sf::RenderWindow& w);

    sf::Vector2i& get_pos();

    sf::RectangleShape& get_sprite();

};