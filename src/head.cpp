

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

bool head::check_collisions()
{
    switch(dir)
    {
        case direction::RIGHT:
            if (pos.x >= window_width / tile_size)
                return true;
            break;
        
        case direction::LEFT:
            if (pos.x <= 0)
                return true;
            break;

        case direction::UP:
            if (pos.y <= 0)
                return true;
            break;
        
        case direction::DOWN:
            if (pos.y >= window_height / tile_size)
                return true;
            break;
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

    sprite.setPosition({ pos.x * tile_size, pos.y * tile_size });

}

void head::set_dir(direction d)
{
    dir = d;
}

direction head::get_dir() const
{
    return dir;
}

void head::generate_segment()
{
    segment_stack.emplace_back();
}
