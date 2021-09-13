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

    void set_pos(sf::Vector2i new_pos);

    sf::Vector2i get_pos();

};