
#include "segment.hpp"
#include <SFML/Graphics.hpp>

segment::segment() :
    sprite {{ tile_size,tile_size }}
{
    sprite.setFillColor(sf::Color::Green);
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
