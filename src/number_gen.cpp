
#include "number_gen.hpp"

#include <iostream>
#include <chrono>

//std::random_device rd;

unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
std::mt19937 gen(seed);

void print_random_range()
{
    std::cout << "Min: " <<gen.min() << "\n";
    std::cout << "Max: " <<gen.max() << "\n";

    std::cout << "1: " <<gen() << "\n";
    std::cout << "2: " <<gen() << "\n";
    std::cout << "3: " <<gen() << "\n";
}
