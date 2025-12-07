// Using the generator for multiple distributions
// std::uniform_int_distribution
// std::discrete_distribution

#include <iostream>
#include <random>
int main() {
    std::default_random_engine pseudo_random_generator;

    std::uniform_int_distribution<int> int_distribution(0, 9);
    std::uniform_real_distribution<float> float_distribution(0.0, 1.0);
    // The rigged_dice distribution will generate a value between 0 and 5, but
    // almost always generates a 5, because the chance to generate a 5 is 100 /
    // 105
    std::discrete_distribution<int> rigged_dice({1, 1, 1, 1, 1, 100});

    std::cout << int_distribution(pseudo_random_generator) << std::endl;
    std::cout << float_distribution(pseudo_random_generator) << std::endl;
    std::cout << (rigged_dice(pseudo_random_generator) + 1) << std::endl;
}