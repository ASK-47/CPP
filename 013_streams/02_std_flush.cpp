// https://www.geeksforgeeks.org/cpp/buffer-flush-means-c/
// std::flush
#include <chrono>
#include <iostream>
#include <thread>

int main() {
    for (int i = 1; i <= 5; ++i) {
        std::cout << i << " ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    //std::cout << std::endl;//is commented output 1 2 3 4 5 1 at once!!! since cout is collecting values
	std::cout << std::endl;//output 1 2 3 4 5 at once!!! cout is flushed (empty)
	
	
    for (int i = 1; i <= 5; ++i) {//output 1 2 3 4 5 at once.
        std::cout << i << " " <<  std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << std::endl;
    return 0;
}