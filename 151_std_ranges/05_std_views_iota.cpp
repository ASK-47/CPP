//AI
//std_views_iota

#include <iostream>
#include <ranges>

int main() {
    
    //std::views::iota produces an infinite range, so always pipe it with something like std::views::take to avoid infinite loops.
    // Generate 0, 1, 2, 3, 4, then square them
    auto squares = std::views::iota(0) | std::views::take(10) | std::views::transform([](int x) { return x * x; });
    for (int square : squares) {
        std::cout << square << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
