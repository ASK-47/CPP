//https://t.me/cpp_ready/1560
//zip_view и chunk_view:

#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>

int main() {
    //1 std::views::zip
    std::vector<int> xs = {1, 2, 3};
    std::vector<char> ys = {'A', 'B', 'C'};
    for (auto [x, y] : std::views::zip(xs, ys)) {
        std::cout << x << ':' << y << ' ' << '\n';
    }

    //2 std::views::zip_transform
    auto sum = std::views::zip_transform(
        [](int a, int b) { return a + b; }, xs,
        ys | std::views::transform([](char c) { return c - 'A'; }));
    for (auto s : sum) {
        std::cout << s << '\n';
    }

    //3 std::views::chunk
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto pack : data | std::views::chunk(2)) {
        std::ranges::for_each(pack, [](int v){ std::cout << v << ' '; });
        std::cout << "|| ";
    }
    std::cout << '\n';

    //4 std::views::zip + std::views::iota
    for (auto [index, v] : std::views::zip(std::views::iota(0), data)) {
        std::cout << index << ':' << v << ' ';
    }
    std::cout << '\n';
    
}