#pragma once

namespace sf
{
    class Event;
}

class head;

void handle_input(const sf::Event& e, const head& s);
