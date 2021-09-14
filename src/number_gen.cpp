
#include "number_gen.hpp"

#include <iostream>
#include <chrono>
#include <vector>

//Default seed derived from current time
unsigned seed = std::random_device{}();

//Create generators
std::default_random_engine gen_default(seed);
std::mt19937 gen_mt19937(seed);

//Generates a random number in the given range using the default random engine.
//Seeded with the time.
int rand_range(int min, int max)
{
    std::uniform_int_distribution<int> range(min,max);
    return range(gen_default);
}

//Generates a random number in the given range using the default random engine.
//Takes in a custom seed.
int rand_range(int min, int max, unsigned seed)
{
    gen_default.seed(seed);
    std::uniform_int_distribution<int> range(min,max);
    return range(gen_default);
}