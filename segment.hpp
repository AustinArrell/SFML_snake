#pragma once

#include "globals.hpp"
#include <SFML/Graphics.hpp>

class segment
{
    sf::Vector2i pos;

    sf::RectangleShape sprite;

public:

    segment();

    void draw(sf::RenderWindow& window) const;

    void set_pos(int x, int y);

};