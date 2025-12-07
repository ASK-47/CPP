//True random value generator
//std::random_device

#include <iostream>
#include <random>

int main() {
    std::random_device crypto_random_generator;// a seed source for the random number engine
    //std::mt19937 gen(crypto_random_generator());  // mersenne_twister_engine seeded with rd()

    std::uniform_int_distribution<int> int_distribution(0, 9);
    
    int actual_distribution[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    for (int i = 0; i < 100000; i++) {
        int result = int_distribution(crypto_random_generator);
        //int result = int_distribution(gen);
        actual_distribution[result]++;
    }
    
    for (int i = 0; i < 10; i++) {
        std::cout << actual_distribution[i] << " ";
    }    
}