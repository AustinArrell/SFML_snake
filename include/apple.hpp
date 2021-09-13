
#pragma once

#include <SFML/Graphics.hpp>
#include <random>

class apple
{
    sf::Vector2i pos = {5,5};

    sf::RectangleShape sprite;

public:
    apple();

    void spawn();

    void draw(sf::RenderWindow& w);

};