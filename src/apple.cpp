
#include "apple.hpp"
#include "globals.hpp"
#include <random>
#include <iostream>

apple::apple() :
    sprite ({ tile_size,tile_size })
{
    
    sprite.setPosition(pos.x * tile_size, pos.y * tile_size);

    sprite.setFillColor(sf::Color::Red);
}

void apple::spawn()
{
   
}

void apple::draw(sf::RenderWindow& w)
{
    w.draw(sprite);
}