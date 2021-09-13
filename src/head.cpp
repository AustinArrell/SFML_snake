

#include "head.hpp"
#include "globals.hpp"
#include <iostream>

head::head()
{

    dir = direction::RIGHT;

    sprite.setSize({ tile_size,tile_size });

    sprite.setPosition(pos.x * tile_size, pos.y * tile_size);

    sprite.setFillColor(sf::Color::Blue);
}

void head::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);

    for(const auto& seg : segment_stack)
    {
        seg.draw(window);
    }
}

bool head::check_collisions(){
    if (pos.x >= window_width / tile_size)
        return true;

    if (pos.x < 0)
        return true;

    if (pos.y < 0)
        return true;

    if (pos.y >= window_height / tile_size)
        return true;

    for (auto& seg : segment_stack)
    {
        if (sprite.getGlobalBounds().intersects(seg.get_sprite().getGlobalBounds()))
            return true;
    }

    return false;
}


void head::update()
{

    //set each segment pos to the one in front of it.
    for (int i = segment_stack.size()-1; i > 0; i--)
    {
        segment_stack[i].set_pos(segment_stack[i-1].get_pos());
    }
    if(segment_stack.size() > 0)
    {
        segment_stack[0].set_pos(pos);
    }

    //Move the head based on direction
    switch (dir)
    {
    case direction::RIGHT:
        pos.x += 1;
        break;

    case direction::LEFT:
        pos.x -= 1;
        break;

    case direction::UP:
        pos.y -= 1;
        break;

    case direction::DOWN:
        pos.y += 1;
        break;
    }

    sprite.setPosition({ static_cast<float>(pos.x * tile_size), static_cast<float>(pos.y * tile_size)});

}

bool head::validate_location(sf::RectangleShape& other_obj)
{
    for (auto& seg : segment_stack)
    {
        if(other_obj.getGlobalBounds().intersects(seg.get_sprite().getGlobalBounds()))
            return false;
    }

    return true;
}

void head::clear_stack()
{
    segment_stack.clear();
}

void head::generate_segment()
{
    segment_stack.emplace_back();
}

void head::set_dir(direction d)
{
    dir = d;
}

direction head::get_dir() const
{
    return dir;
}

const sf::Vector2i& head::get_pos()
{
    return pos;
}

const sf::RectangleShape& head::get_sprite()
{
    return sprite;
}

void head::set_pos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}