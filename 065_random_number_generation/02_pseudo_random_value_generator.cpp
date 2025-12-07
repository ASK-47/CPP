// Pseudo-random number
// std::default_random_engine

// A pseudo-random number generator generates values that can be guessed based
// on previously generated values. In other words: it is deterministic. Do not
// use a pseudo-random number generator in situations where a true random number
// is required.

#include <iostream>
#include <random>

int main() {
    
    std::default_random_engine pseudo_random_generator;//std::random_device crypto_random_generator == for true random value generator
    std::uniform_int_distribution<int> int_distribution(0, 9);

    int actual_distribution[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    for (int i = 0; i < 100000; i++) {
        int result = int_distribution(pseudo_random_generator);
        actual_distribution[result]++;
    }
    
    for (int i = 0; i <= 9; i++) {
        std::cout << actual_distribution[i] << " ";
    }    
}