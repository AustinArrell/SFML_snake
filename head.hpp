#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "segment.hpp"
#include "globals.hpp"


class head
{
	std::vector<segment> segment_stack;

	sf::RectangleShape sprite;

	sf::Vector2<float> pos = { 5,5 };
	
	direction dir;
	
public:

	head();

	void set_dir(direction d);

	direction get_dir() const;

	void draw(sf::RenderWindow& window) const;

	void update();

	bool check_collisions();

};

