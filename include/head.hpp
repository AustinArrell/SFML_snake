#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "segment.hpp"
#include "globals.hpp"


class head
{
    std::vector<segment> segment_stack;

    sf::RectangleShape sprite;

    sf::Vector2i pos = { window_width/tile_size/2, window_height/tile_size/2};
    
    direction dir;

    direction queued_dir;
    
public:
    bool check_collisions();

    head();

    void draw(sf::RenderWindow& window) const;

    void update();

    void generate_segment();

    bool validate_location(sf::RectangleShape& pos_to_check);

    void clear_stack();

    void set_dir(direction d);

    direction get_dir() const;

    const sf::Vector2i& get_pos();

    const sf::RectangleShape& get_sprite();

    void set_pos(int x, int y);
};
