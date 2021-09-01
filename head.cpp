
#include <SFML/Graphics.hpp>
#include "head.hpp"
#include "globals.hpp"
#include <iostream>

head::head()
{
	dir = direction::RIGHT;

	sprite.setSize({ tile_size,tile_size });

	sprite.setFillColor(sf::Color::Green);
}


void head::draw(sf::RenderWindow& window) const
{
	window.draw(sprite);
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

	//set last segment pos to head pos
	//tail = segment_stack.size() - 1;
	//segment_stack[tail].

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
