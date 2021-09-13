
#include "segment.hpp"
#include <SFML/Graphics.hpp>

segment::segment() :
    sprite {{ tile_size,tile_size }}
{
    sprite.setFillColor(sf::Color::Green);
    
    sprite.setPosition(-200,-200);
}

void segment::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}

void segment::set_pos(int x, int y)
{
    pos.x = x;
    pos.y = y;
    sprite.setPosition({ pos.x * tile_size, pos.y * tile_size });
}

void segment::set_pos(sf::Vector2i new_pos)
{
    pos = new_pos;
    sprite.setPosition({ pos.x * tile_size, pos.y * tile_size });
}

sf::Vector2i segment::get_pos()
{
    return pos;
}

sf::RectangleShape& segment::get_sprite()
{
    return sprite;
}
