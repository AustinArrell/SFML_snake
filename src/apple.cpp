
#include "apple.hpp"
#include "globals.hpp"
#include "number_gen.hpp"


apple::apple() :
    sprite ({ tile_size,tile_size })
{
    sprite.setPosition(pos.x * tile_size, pos.y * tile_size);

    sprite.setFillColor(sf::Color::Red);
}

void apple::move()
{
    pos.x = rand_range(0, (window_width/tile_size) - 1);
    pos.y = rand_range(0, (window_height/tile_size) - 1);
}

void apple::update()
{
    sprite.setPosition(pos.x * tile_size, pos.y * tile_size);
}

void apple::draw(sf::RenderWindow& w)
{
    w.draw(sprite);
}

sf::Vector2i& apple::get_pos()
{
    return pos;
}

sf::RectangleShape& apple::get_sprite()
{
    return sprite;
}