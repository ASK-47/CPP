//AI
//std_ranges_copy

#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>  // For std::ranges::copy and std::back_inserter

int main() {
    // Generate 0, 1, 2, ..., up to 10 values
    auto sequence = std::views::iota(0) | std::views::take(10);
    for (int num : sequence) {
        std::cout << num << " ";
    }
    std::cout << '\n';
    
    // Then, collect into a vector using std::ranges::copy
    std::vector<int> vec;
    std::ranges::copy(sequence, std::back_inserter(vec));
    for (int num : vec) {
        std::cout << num << " ";
    }   
    
    return 0;
}

